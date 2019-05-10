/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:02:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/10 11:38:41 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h" //

void	put_line(t_fdf *fdf, int ox, int oy)
{
	t_point	c;
	t_point	o;

	c.x = (int)fdf->project[oy * fdf->width + ox].x;
	c.y = (int)fdf->project[oy * fdf->width + ox].y;
	if (ox >= 0 && ox < fdf->width - 1)
	{
		o.x = (int)fdf->project[oy * fdf->width + ox + 1].x;
		o.y = (int)fdf->project[oy * fdf->width + ox + 1].y;
		bresenham(fdf, c, o);
	}
	if (oy >= 0 && oy < fdf->nblines - 1)
	{
		o.x = (int)fdf->project[(oy + 1) * fdf->width + ox].x;
		o.y = (int)fdf->project[(oy + 1) * fdf->width + ox].y;
		bresenham(fdf, c, o);
	}
}

#include "math.h" //

t_point	project(t_vector3 v)
{
	t_point	res;

	res.x = (int)(v.x * (100 / v.z));
	res.y = (int)(v.y * (100 / v.z));
	return (res);
}


t_vector2	project_point(t_fdf *fdf, int x, int y)
{
	t_vector3	v;
	
	// (void)fdf;
	v = vec_3_sub(fdf->map[y * fdf->width + x], fdf->cam.pos);
	// v = mat_4_mul_v(fdf->cam.projection, v);
	v = mat_4_mul_v(fdf->cam.rotation, v);
	if (v.z == 0)
		v.z += 0.0001;
	// return ((t_vector2){(v.x * W_WIDTH) / (2.0 *  v.z) + W_WIDTH / 2.0, (v.y * W_HEIGHT) / (2.0 / v.z) + W_HEIGHT / 2.0});
	return ((t_vector2){v.x * 100 / v.z, v.z * 100 / v.z});
}

void	put_line2(t_fdf *fdf, int ox, int oy)
{
	t_point	c;
	t_point	o;
	t_vector3	v;

	v = fdf->map[oy * fdf->width + ox];
	if (!v.z)
		v.z += 0.1;
	c = project(v);
	if (ox >= 0 && ox < fdf->width - 1)
	{
		v = fdf->map[oy * fdf->width + ox + 1];
		if (!v.z)
			v.z += 0.1;
		// t_vector2	vp;
		// vp = project_point(fdf, ox + 1, oy);
		// o.x = vp.x;
		// o.y = vp.y;
		// (map[i] - cam_pos) * matrix_projection * matrix_rotation;
		// v.x * 100 / v.z;
		// v.y * 100 / v.z;
		o = project(v);
		bresenham(fdf, c, o);
	}
	if (oy >= 0 && oy < fdf->nblines - 1)
	{
		v = fdf->map[(oy + 1) * fdf->width + ox];
		if (!v.z)
			v.z += 0.1;
		// t_vector2 vp;
		// vp = project_point(fdf, ox, oy + 1);
		// o.x = vp.x;
		// o.y = vp.y;
		o = project(v);
		if (o.x >= 0 && o.y >= 0 && o.x < 500 && o.y < 500)
			bresenham(fdf, c, o);
	}
}

int		put_pixels(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fdf->nblines && (x = -1))
		while (++x < fdf->width)
			;
			// put_line(fdf, x, y);
	return (0);
}

int		calc_map(t_fdf *fdf)
{
	int	y;
	int	x;
	y = -1;
	while (++y < fdf->nblines && (x = -1))
		while (++x < fdf->width)
		{
			t_vector3	v = fdf->map[y * fdf->width + x];
			mlx_pixel_put(fdf->mlx_ptr, fdf->window,   // affiche 42 en points
				v.x * (100 / v.z),
				v.y * (100 / v.z), 0xFF0000);
			v = mat_4_mul_v(fdf->cam.projection, v);
			// mlx_pixel_put(fdf->mlx_ptr, fdf->window,   // post projection
			// 	v.x * (100 / v.z),
			// 	v.y * (100 / v.z), 0xFF0000);
			// v = mat_4_mul_v(fdf->cam.rotation, v);
			// mlx_pixel_put(fdf->mlx_ptr, fdf->window,   
			// 	v.x * (500 / v.z),
			// 	v.y * (500 / v.z), 0xFF0000);
			put_line2(fdf, x, y);
			fdf->project[y * fdf->width + x] = project_point(fdf, x, y);
		}
	return (0);
}

int			draw_map(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->window);
	calc_map(fdf);
	put_pixels(fdf);
	return (0);
}


// viewMatrix = projMatrix * cameraTranslationMatrix4x4 * cameraRotationMatrix4x4;
