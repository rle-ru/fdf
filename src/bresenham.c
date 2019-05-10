/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:07:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/10 15:23:02 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	init_bre(t_point *o, t_point *t, double *deltax, double *deltay)
{
	*deltax = t->x - o->x;
	*deltay = t->y - o->y;
}

static void	init_bre2(double *deltaerr, double *error, t_point *o, t_point *p)
{
	*deltaerr = 1.0;
	*error = 0;
	p->y = o->y;
	p->x = o->x;
}

void		bresenham(t_fdf *fdf, t_point o, t_point t)
{
	double	deltax;
	double	deltay;
	double	deltaerr;
	double	error;
	t_point	p;

	init_bre(&o, &t, &deltax, &deltay);
	init_bre2(&deltaerr, &error, &o, &p);
	if (deltax)
		deltaerr = deltay / deltax;
	deltaerr = deltaerr < 0 ? -deltaerr : deltaerr;
	while (p.x != t.x || p.y != t.y)
	{
		if (p.x >= 0 && p.x < 500 && p.y >= 0 && p.y < 500)
			mlx_pixel_put(fdf->mlx_ptr, fdf->window, p.x, p.y, 0xFF0000);
		if ((error += deltaerr) >= 0.5)
		{
			if (p.y != t.y)
				p.y += p.y > t.y ? -1 : 1;
			error -= 1.0;
		}
		if (p.x != t.x)
			p.x += p.x > t.x ? -1 : 1;
	}
}
