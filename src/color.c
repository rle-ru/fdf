/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:51:56 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/14 15:28:01 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>
int		get_color(int from, int to, double a)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	a = fabs(a);
	r = (unsigned char)((from >> 16) & 0xFF);
	r += ((unsigned char)((to >> 16) & 0xFF) - r) * a;
	g = (unsigned char)((from >> 8) & 0xFF);
	g += ((unsigned char)((to >> 8) & 0xFF) - g) * a;
	b = (unsigned char)(from & 0xFF);
	b += ((unsigned char)to - b) * a;
	int res = r << 16 | g << 8 | b;
	return (res);
}
