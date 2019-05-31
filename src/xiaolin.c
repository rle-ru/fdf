/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:29:56 by dacuvill          #+#    #+#             */
/*   Updated: 2019/05/31 17:31:43 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <math.h>

static int	ipart(double x)
{
	return ((int)x);
}

static void	check_for_swap(t_xiao *xiao, t_point *o, t_point *t)
{
	if ((*xiao).steep)
	{
		swap(&(*o).x, &(*o).y);
		swap(&(*t).x, &(*t).y);
	}
	if ((*o).x > (*t).x)
	{
		swap(&(*o).x, &(*t).x);
		swap(&(*o).y, &(*t).y);
	}
}

static void	xiaolin_while2(t_fdf *fdf, t_point *color, t_xiao *xiao)
{
	(*xiao).x = (*xiao).xpx11;
	while ((*xiao).x <= (*xiao).xpx12)
	{
		put_pixel(fdf, (*xiao).x, ipart((*xiao).inter),
			get_color((*color).x, (*color).y, (*xiao).pos / (*xiao).rel));
		put_pixel(fdf, (*xiao).x, ipart((*xiao).inter) - 1,
			get_color((*color).x, (*color).y, (*xiao).pos / (*xiao).rel));
		(*xiao).inter += (*xiao).gradient;
		(*xiao).x++;
		(*xiao).pos++;
	}
}

static void	xiaolin_while1(t_fdf *fdf, t_point *color, t_xiao *xiao)
{
	(*xiao).x = (*xiao).xpx11;
	while ((*xiao).x <= (*xiao).xpx12)
	{
		put_pixel(fdf, ipart((*xiao).inter), (*xiao).x,
			get_color((*color).x, (*color).y, (*xiao).pos / (*xiao).rel));
		put_pixel(fdf, ipart((*xiao).inter) - 1, (*xiao).x,
			get_color((*color).x, (*color).y, (*xiao).pos / (*xiao).rel));
		(*xiao).inter += (*xiao).gradient;
		(*xiao).x++;
		(*xiao).pos++;
	}
}

void		xiaolin(t_fdf *fdf, t_point o, t_point t, t_point color)
{
	t_xiao	xiao;

	xiao.rel = (ft_abs(t.x - o.x) + ft_abs(t.y - o.y));
	xiao.pos = 0;
	xiao.steep = ft_abs(t.y - o.y) > ft_abs(t.y - o.x);
	check_for_swap(&xiao, &o, &t);
	xiao.dx = t.x - o.x;
	xiao.dy = t.y - o.y;
	xiao.gradient = xiao.dy / xiao.dx;
	if (!xiao.dx)
		xiao.gradient = 1;
	xiao.xpx11 = o.x;
	xiao.xpx12 = t.x;
	xiao.inter = o.y;
	if (xiao.steep)
		xiaolin_while1(fdf, &color, &xiao);
	else
		xiaolin_while2(fdf, &color, &xiao);
}
