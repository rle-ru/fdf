/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:07:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/02 13:44:59 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <math.h>

static void	bresenham2(t_point *d, t_point *o, t_point *e, t_point *s)
{
	(*e).y = (*e).x;
	if ((*e).y > -(*d).x)
	{
		(*e).x -= (*d).y;
		(*o).x += (*s).x;
	}
	if ((*e).y < (*d).y)
	{
		(*e).x += (*d).x;
		(*o).y += (*s).y;
	}
}

void		bresenham(t_fdf *fdf, t_point o, t_point t, t_point color)
{
	t_point	d;
	t_point	s;
	t_point	e;
	double	rel;
	double	pos;

	rel = (ft_abs(t.x - o.x) + ft_abs(t.y - o.y));
	pos = 0;
	d.x = ft_abs(t.x - o.x);
	s.x = o.x < t.x ? 1 : -1;
	d.y = ft_abs(t.y - o.y);
	s.y = o.y < t.y ? 1 : -1;
	e.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (o.x != t.x || o.y != t.y)
	{
		if (o.x >= 0 && o.x < fdf->canvas.w_width
			&& o.y >= 0 && o.y < fdf->canvas.w_height)
		{
				fdf->canvas.img.img[((o.y * (int)fdf->canvas.w_width)
					+ o.x)] = get_color(color.x, color.y, pos / rel);
		}
		else
			break ;
		bresenham2(&d, &o, &e, &s);
		++pos;
	}
}
