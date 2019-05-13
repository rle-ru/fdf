/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:02:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/13 13:27:45 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "math.h"

t_point		project(t_vector3 v)
{
	t_point	res;

	res.x = (int)(v.x * (100 / v.z));
	res.y = (int)(v.y * (100 / v.z));
	return (res);
}

t_vector2	project_point(t_fdf *fdf, int x, int y)
{
	t_vector3	v;

	v = fdf->map[y * fdf->width + x];
	v.z *= 0.1;
	v = vec_3_sub(v, fdf->cam.pos);
	if (!fdf->proj)
		v = mat_4_mul_v(fdf->cam.rotation, v);
	if (v.z < 0.1)
		return ((t_vector2){NAN, NAN});
	v = mat_4_mul_v(fdf->cam.projection[fdf->proj], v);
	return ((t_vector2){(v.x + 0.25) / v.z * W_WIDTH,
			(v.y + 0.25) / v.z * W_HEIGHT});
}

int			put_pixels(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fdf->nblines && (x = -1))
		while (++x < fdf->width)
			put_line(fdf, x, y);
	return (0);
}

int			calc_map(t_fdf *fdf)
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
