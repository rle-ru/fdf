/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:51:56 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/13 16:11:40 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int from, int to, double a)
{
	int	r;
	int	g;
	int	b;

	r = from & 0xFF0000;
	g = from & 0xFF00;
	b = from & 0xFF;
	r += ((to & 0xFF0000) - from) * a;
	g += ((to & 0xFF00) - from) * a;
	b += ((to & 0xFF) - from) * a;
	return (r | g | b);
}
