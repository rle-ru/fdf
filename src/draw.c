/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:02:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/09 17:40:02 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h" //

void	put_line(t_fdf *fdf, int ox, int oy)
{
	t_point	c;
	// t_point	o;

	c.x = fdf->project[oy * fdf->width + ox].x;
	c.y = fdf->project[oy * fdf->width + ox].y;
	mlx_pixel_put(fdf->mlx_ptr, fdf->window, c.x, c.y, 0xFF0000);
	// if (ox >= 0 && ox < fdf->width - 1)
	// {
	// 	o.x = fdf->project[oy * fdf->width + ox + 1].x;
	// 	o.y = fdf->project[oy * fdf->width + ox + 1].y;
	// 	bresenham(fdf, c, o);
	// }
	// if (oy >= 0 && oy < fdf->nblines - 1)
	// {
	// 	o.x = fdf->project[(oy + 1) * fdf->width + ox].x;
	// 	o.y = fdf->project[(oy + 1) * fdf->width + ox].y;
	// 	bresenham(fdf, c, o);
	// }
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

t_vector2	project_point(t_fdf *fdf, int x, int y)
{
	t_vector3	v;
	
	v = vec_3_sub(fdf->map[y * fdf->width + x], fdf->cam.pos);
	v = mat_4_mul_v(fdf->cam.rotation, v);
	if (v.z == 0)
		v.z += 0.0001;
	v = mat_4_mul_v(fdf->cam.projection, v);
	return ((t_vector2){v.x * (100 / v.z), v.y * (100 / v.z)});
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
