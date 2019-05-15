/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:51:56 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/15 21:58:26 by rle-ru           ###   ########.fr       */
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
