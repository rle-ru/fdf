/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:51:56 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/17 20:31:26 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		get_gradient(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

int			apply_gradient(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int			get_color(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = apply_gradient((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = apply_gradient((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = apply_gradient(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

void		select_color(t_fdf *fdf, int i)
{
	if (-fdf->map[i].z < 0)
		fdf->map[i].color = get_color(C_DEEP, C_GROUND, get_gradient(-fdf->map[i].z,
			fdf->parser.minz, 0));
	if (-fdf->map[i].z >= 0)
		fdf->map[i].color = get_color(C_GROUND, C_10, get_gradient(-fdf->map[i].z,
			0, 20));
	if (-fdf->map[i].z >= 10)
		fdf->map[i].color = get_color(C_10, C_20, get_gradient(-fdf->map[i].z,
			10, 20));
	if (-fdf->map[i].z >= 20)
		fdf->map[i].color = get_color(C_20, C_100, get_gradient(-fdf->map[i].z,
			20, 100));
	if (-fdf->map[i].z >= 100)
		fdf->map[i].color = get_color(C_100, C_200, get_gradient(-fdf->map[i].z,
			100, 200));
	if (-fdf->map[i].z >= 200)
		fdf->map[i].color = C_200;
}

