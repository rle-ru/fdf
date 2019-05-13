/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:07:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/13 16:15:22 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include <math.h>

void		bresenham(t_fdf *fdf, t_point o, t_point t, t_color color)
{
	t_point	d;
	t_point	s;
	t_point	e;
	double	rel;
	double	pos;

	rel = (abs(t.x - o.x) + abs(t.y - o.y));
	pos = 0;
	d.x = abs(t.x - o.x);
	s.x = o.x < t.x ? 1 : -1;
	d.y = abs(t.y - o.y);
	s.y = o.y < t.y ? 1 : -1;
	e.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (o.x != t.x || o.y != t.y)
	{
		if (o.x >= 0 && o.x < 500 && o.y >= 0 && o.y < 500)
			mlx_pixel_put(fdf->mlx_ptr, fdf->window, o.x, o.y,
				get_color(color.from, color.to, (double)(-pos / rel)));
		e.y = e.x;
		if (e.y > -d.x)
		{
			e.x -= d.y;
			o.x += s.x;
		}
		if (e.y < d.y)
		{
			e.x += d.x;
			o.y += s.y;
		}
		++pos;
	}
}

void		put_line(t_fdf *fdf, int ox, int oy)
{
	t_point	c;
	t_point	o;
	t_color	color;

	c.x = (int)fdf->project[oy * fdf->width + ox].x;
	c.y = (int)fdf->project[oy * fdf->width + ox].y;
	color.from = fdf->map[oy * fdf->width + ox].color;
	if (!isnan(c.x) && ox >= 0 && ox < fdf->width - 1)
	{
		color.to = fdf->map[oy * fdf->width + ox + 1].color;
		o.x = (int)fdf->project[oy * fdf->width + ox + 1].x;
		o.y = (int)fdf->project[oy * fdf->width + ox + 1].y;
		if (!isnan(o.x))
			bresenham(fdf, c, o, color);
	}
	if (!isnan(c.y) && oy >= 0 && oy < fdf->nblines - 1)
	{
		color.to = fdf->map[(oy + 1) * fdf->width + ox].color;
		o.x = (int)fdf->project[(oy + 1) * fdf->width + ox].x;
		o.y = (int)fdf->project[(oy + 1) * fdf->width + ox].y;
		if (!isnan(o.x))
			bresenham(fdf, c, o, color);
	}
}
