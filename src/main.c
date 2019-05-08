/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 08:11:48 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/08 18:19:50 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h" //
#include <math.h>
#include "fdf.h"

void	bresenham(t_fdf *fdf, int ox, int oy, int tx, int ty)
{
	double		deltax;
	double		deltay;
	double	deltaerr;
	double	error;
	int		y;
	int		x;

	deltax = tx - ox;
	deltay = ty - oy;
	deltaerr = 1.0;
	if (deltax)
		deltaerr = deltay / deltax;
	deltaerr = deltaerr < 0 ? -deltaerr : deltaerr;
	error = 0;
	y = oy;
	x = ox;
	while (x != tx || y != ty)
	{
		if (x >= 0 && x < 500 && y >= 0 && y < 500)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->window, x, y, 0xFF0000);
			// ft_printf("x = %d; tx = %d\ny = %d; ty = %d\n", x, tx, y, ty);
		}
		error += deltaerr;
		if (error >= 0.5)
		{
			if (deltay)
				y += deltay < 0 ? -1 : 1;
			error -= 1.0;
		}
		if (deltax)
			x += deltax < 0 ? -1 : 1;
		
	}
}

void	put_line(t_fdf *fdf, int ox, int oy)
{
	int		cx;
	int		cy;

	cx = fdf->map[oy * fdf->width + ox].x;
	cy = fdf->map[oy * fdf->width + ox].y;
	if (ox < fdf->width - 1)
		bresenham(fdf, cx, cy, fdf->map[oy * fdf->width + ox + 1].x, fdf->map[oy * fdf->width + ox + 1].y);
	if (oy < fdf->nblines - 1)
		bresenham(fdf, cx, cy, fdf->map[(oy + 1) * fdf->width + ox].x, fdf->map[(oy + 1) * fdf->width + ox].y);
}

int		put_pixels(t_fdf *fdf)
{
	int	x;
	int	y;
	int	x2;
	int	y2;

	y = -1;
	while (++y < fdf->nblines && (x = -1))
	{
		while (++x < fdf->width)
		{
			x2 = fdf->map[y * fdf->width + x].x;
			y2 = fdf->map[y * fdf->width + x].y;
			if (x2 >= 0 && x2 < 500 && y2 >= 0 && y2 < 500)
			{
				put_line(fdf, x, y);
				// mlx_pixel_put(fdf->mlx_ptr, fdf->window, x2, y2, 0xFF0000);
			}
		}
	}
	return (0);
}

int		calc_map(t_fdf *fdf)
{
	int	y;
	int	x;
	double	z;
	int	mult;
	int	dist;

	dist = 150;
	mult = 10;
	y = -1;
	while (++y < fdf->nblines && (x = -1))
		while (++x < fdf->width)
		{
			z = fdf->map[y * fdf->width + x].z + 0.0001 - fdf->cam.z;
			ft_printf("C't'encule : %f\n", z);
			fdf->map[y * fdf->width + x].x = ((float)x - fdf->cam.x / z);
			fdf->map[y * fdf->width + x].y = ((float)y - fdf->cam.y / z);
		}
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;
	t_error	ret;

	ft_bzero(&fdf, sizeof(t_fdf));
	if ((ret = ft_open_file(ac, av, &fdf)) != ok)
		ft_leave(ret, &fdf);
	if ((ret = ft_parse_file(&fdf)))
		ft_leave(ret, &fdf);
	ft_init_fdf(&fdf);
	fdf.cam.z = -10;
	calc_map(&fdf);
	// int	i = 0;
	// while (i < fdf.nblines * fdf.width)
	// {
	// 	ft_printf("x : %d, y : %d\n", fdf.map[i].x, fdf.map[i].y);
	// 	++i;
	// }
	// bresenham(&fdf, 10, 10, 10, 100);
	// bresenham(&fdf, 10, 10, 100, 100);
	// bresenham(&fdf, 10, 10, 100, 10);
	// bresenham(&fdf, 100, 10, 100, 100);
	// bresenham(&fdf, 100, 100, 10, 10);
	put_pixels(&fdf);
	mlx_loop(fdf.mlx_ptr);
	ft_leave(ok, &fdf);
	return (0);
}
