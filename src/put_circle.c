/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:35:17 by dacuvill          #+#    #+#             */
/*   Updated: 2019/05/28 18:13:14 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

static void	put_circle2(int *x, int *y, int *m)
{
	if (*m >= *x * 2)
	{
		*m = *m - 2 * *x + 1;
		++*x;
	}
	else if (*m < 2 * (10 - *y))
	{
		*m = *m + 2 * *y - 1;
		--*y;
	}
	else
	{
		*m = *m + 2 * (*y - *x - 1);
		--*y;
		++*x;
	}
}

void		put_circle(t_fdf *fdf)
{
	int			x;
	int			y;
	int			m;
	t_vector2	v;

	x = 0;
	y = 10;
	m = y - 1;
	v = project_point(fdf, fdf->crea.current.x, fdf->crea.current.y);
	while (y >= x)
	{
		put_pixel(fdf, v.x + x, v.y + y, 0xFFFF);
		put_pixel(fdf, v.x + y, v.y + x, 0xFFFF);
		put_pixel(fdf, v.x - x, v.y + y, 0xFFFF);
		put_pixel(fdf, v.x - y, v.y + x, 0xFFFF);
		put_pixel(fdf, v.x + x, v.y - y, 0xFFFF);
		put_pixel(fdf, v.x + y, v.y - x, 0xFFFF);
		put_pixel(fdf, v.x - x, v.y - y, 0xFFFF);
		put_pixel(fdf, v.x - y, v.y - x, 0xFFFF);
		put_circle2(&x, &y, &m);
	}
}
