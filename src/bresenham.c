/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:07:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/10 22:25:00 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	bresenham(t_fdf *fdf, t_point o, t_point t)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
	
	dx = abs(t.x - o.x);
	sx = o.x < t.x ? 1 : -1;
	dy = abs(t.y - o.y);
	sy = o.y < t.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (o.x != t.x || o.y != t.y)
	{
		if (o.x >= 0 && o.x < 500 && o.y >= 0 && o.y < 500)
			mlx_pixel_put(fdf->mlx_ptr, fdf->window, o.x, o.y, 0xFF0000);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			o.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			o.y += sy;
		}
	}
}
