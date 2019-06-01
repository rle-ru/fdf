/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:25:24 by dacuvill          #+#    #+#             */
/*   Updated: 2019/06/01 20:33:54 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

static void	put_line2(t_fdf *fdf, t_point *c, t_point *o, t_point *color)
{
	int		temp;

	if (!isnan((*o).x))
	{
		if ((*c).x >= 0 && (*c).x < fdf->canvas.w_width
				&& (*c).y >= 0 && (*c).y < fdf->canvas.w_height)
			fdf->f[fdf->drawer].f(fdf, *c, *o, *color);
		else if ((*o).x >= 0 && (*o).x < fdf->canvas.w_width
			&& (*o).y >= 0 && (*o).y < fdf->canvas.w_height)
		{
			temp = (*color).y;
			(*color).y = (*color).x;
			(*color).x = temp;
			fdf->f[fdf->drawer].f(fdf, *o, *c, *color);
		}
	}
}

void		put_line(t_fdf *fdf, int ox, int oy)
{
	t_point	c;
	t_point	o;
	t_point	color;

	c.x = (int)fdf->project[oy * fdf->width + ox].x;
	c.y = (int)fdf->project[oy * fdf->width + ox].y;
	color.x = fdf->map[oy * fdf->width + ox].color;
	if (!isnan(c.x) && ox >= 0 && ox < fdf->width - 1)
	{
		color.y = fdf->map[oy * fdf->width + ox + 1].color;
		o.x = (int)fdf->project[oy * fdf->width + ox + 1].x;
		o.y = (int)fdf->project[oy * fdf->width + ox + 1].y;
		put_line2(fdf, &c, &o, &color);
	}
	if (!isnan(c.y) && oy >= 0 && oy < fdf->height - 1)
	{
		color.y = fdf->map[(oy + 1) * fdf->width + ox].color;
		o.x = (int)fdf->project[(oy + 1) * fdf->width + ox].x;
		o.y = (int)fdf->project[(oy + 1) * fdf->width + ox].y;
		put_line2(fdf, &c, &o, &color);
	}
}
