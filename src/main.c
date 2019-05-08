/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 08:11:48 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/08 13:24:02 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h" //
#include "fdf.h"

// void	puter(t_fdf *fdf, int x, int y, int x2, int y2)
// {
// 	int	x3;
// 	int	y3;
// 	int	multiplier;

// 	if (fdf->map[y * fdf->width + x + 1] == 0)
// 		return ;
// 	multiplier = 5;
// 	if (x != fdf->width - 1 && fdf->map[y * fdf->width + x + 1])
// 	{
// 		x3 = (x + 1) * (100 / fdf->map[y * fdf->width + x + 1]);
// 		x3 *= multiplier;
// 		y3 = (y + 1) * (100 / fdf->map[y * fdf->width + x + 1]);
// 		y3 *= multiplier;
// 		while (x2 != x3 && y2 != y3)
// 		{
// 			if (x3 >= 0 && x3 <= 499 && y3 >= 0 && y3 < 499)
// 				mlx_pixel_put(fdf->mlx_ptr, fdf->window, x3, y3, 0xFF0000);
// 			if (x2 != x3)
// 				x3 += x2 > x3 ? 1 : -1;
// 			if (y2 != y3)
// 				y3 += y2 > y3 ? 1 : -1;
// 		}
// 	}
// 	if (y != fdf->nblines - 1 && fdf->map[(y + 1) * fdf->width + x + 1])
// 	{
// 		x3 = (x + 1) * (100 / fdf->map[y * fdf->width + x + 1]);
// 		x3 *= multiplier;
// 		y3 = (y + 1) * (100 / fdf->map[(y + 1) * fdf->width + x + 1]);
// 		y3 *= multiplier;
// 		while (x2 != x3 && y2 != y3)
// 		{
// 			if (x3 >= 0 && x3 <= 499 && y3 >= 0 && y3 < 499)
// 				mlx_pixel_put(fdf->mlx_ptr, fdf->window, x2, y2, 0xFF0000);
// 			if (x2 != x3)
// 				x3 += x2 > x3 ? 1 : -1;
// 			if (y2 != y3)
// 				y3 += y2 > y3 ? 1 : -1;
// 		}
// 	}
// }

void	put_line(t_fdf *fdf, int ox, int oy)
{
	int		tx;
	int		ty;
	int		cx;
	int		cy;

	if (ox < fdf->width)
	{
		cx = fdf->map[oy * fdf->width + ox].x;
		cy = fdf->map[oy * fdf->width + ox].y;
		tx = fdf->map[oy * fdf->width + ox + 1].x;
		ty = fdf->map[oy * fdf->width + ox + 1].y;
		while (cx != tx && cy != ty)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->window, cx, cy, 0xFF0000);
			cx += tx > cx ? 1 : -1;
			cy += ty > cy ? 1 : -1;
		}
	}
	if (oy < fdf->nblines)
	{
		cx = fdf->map[oy * fdf->width + ox].x;
		cy = fdf->map[oy * fdf->width + ox].y;
		tx = fdf->map[(oy + 1) * fdf->width + ox].x;
		ty = fdf->map[(oy + 1) * fdf->width + ox].y;
		while (cx != tx && cy != ty)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->window, cx, cy, 0xFF0000);
			cx += tx > cx ? 1 : -1;
			cy += ty > cy ? 1 : -1;
		}
	}
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
	int	z;
	int	mult;

	mult = 2;
	y = -1;
	while (++y < fdf->nblines && (x = -1))
		while (++x < fdf->width)
		{
			z = fdf->map[y * fdf->width + x].z;
			if (z)
			{
				fdf->map[y * fdf->width + x].x = (x * (100 / z)) * mult;
				fdf->map[y * fdf->width + x].y = (y * (100 / z)) * mult;
			}
			else
			{
				fdf->map[y * fdf->width + x].x = -1;
				fdf->map[y * fdf->width + x].y = -1;
			}
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
	calc_map(&fdf);
	put_pixels(&fdf);
	mlx_loop(fdf.mlx_ptr);
	ft_leave(ok, &fdf);
	return (0);
}
