/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:02:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/10 13:50:43 by rle-ru           ###   ########.fr       */
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
	
	v = vec_3_sub(fdf->map[y * fdf->width + x], fdf->cam.pos);
	v = mat_4_mul_v(fdf->cam.projection, v);
	v = mat_4_mul_v(fdf->cam.rotation, v);
	v = mat_4_mul_v(fdf->unit, v);
	// if (v.z == 0)
	// 	v.z += 0.0001;
	return ((t_vector2){v.x / v.z * W_WIDTH, v.y / v.z * W_HEIGHT});
}

int		put_pixels(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fdf->nblines && (x = -1))
		while (++x < fdf->width)
			put_line(fdf, x, y);
	return (0);
}

int		calc_map(t_fdf *fdf)
{
	int	y;
	int	x;
	y = -1;
	while (++y < fdf->nblines && (x = -1))
		while (++x < fdf->width)
			fdf->project[y * fdf->width + x] = project_point(fdf, x, y);
	return (0);
}

int			draw_map(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->window);
	calc_map(fdf);
	put_pixels(fdf);
	return (0);
}
