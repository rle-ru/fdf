/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:29:56 by dacuvill          #+#    #+#             */
/*   Updated: 2019/05/29 18:31:52 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <math.h>

void		swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int			ipart(double x)
{
	return ((int)x);
}

double		fpart(double x)
{
	return (x > 0 ? x - ipart(x) : x - (ipart(x) + 1));
}

double		rfpart(double x)
{
	return (1 - fpart(x));
}

int			is_legit(t_fdf *fdf, int x, int y)
{
	if (x >= 0 && x < fdf->canvas.w_width && y >= 0 && y < fdf->canvas.w_height)
		return (0);
	return (1);
}

void		xiaolin(t_fdf *fdf, t_point o, t_point t, t_point color)
{
	int		steep;
	double	dx;
	double	dy;
	double	gradient;
	int		xpx11;
	int		xpx12;
	double	inter;
	int		x;
	double	rel;
	double	pos;

	rel = (ft_abs(t.x - o.x) + ft_abs(t.y - o.y));
	pos = 0;

	steep = ft_abs(t.y - o.y) > ft_abs(t.y - o.x);
	if (steep)
	{
		swap(&o.x, &o.y);
		swap(&t.x, &t.y);
	}
	if (o.x > t.x)
	{
		swap(&o.x, &t.x);
		swap(&o.y, &t.y);
	}
	dx = t.x - o.x;
	dy = t.y - o.y;
	gradient = dy / dx;
	if (!dx)
		gradient = 1;
	xpx11 = o.x;
	xpx12 = t.x;
	inter = o.y;
	if (steep)
	{
		x = xpx11;
		while (x <= xpx12)
		{
			//if (is_legit(fdf, ipart(inter), x))
			//	break ;
			put_pixel(fdf, ipart(inter), x, get_color(color.x, color.y, pos / rel));
			put_pixel(fdf, ipart(inter) - 1, x, get_color(color.x, color.y, pos / rel));
			inter += gradient;
			++x;
			++pos;
		}
	}
	else
	{
		x = xpx11;
		while (x <= xpx12)
		{
			//if (is_legit(fdf, x, ipart(inter)))
			//	break ;
			put_pixel(fdf, x, ipart(inter), get_color(color.x, color.y, pos / rel));
			put_pixel(fdf, x, ipart(inter) - 1, get_color(color.x, color.y, pos / rel));
			inter += gradient;
			++x;
			++pos;
		}
	}
	
}