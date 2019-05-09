/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 08:11:48 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/09 02:04:19 by rle-ru           ###   ########.fr       */
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

	cx = fdf->project[oy * fdf->width + ox].x;
	cy = fdf->project[oy * fdf->width + ox].y;
	if (ox < fdf->width - 1)
		bresenham(fdf, cx, cy, fdf->project[oy * fdf->width + ox + 1].x, fdf->project[oy * fdf->width + ox + 1].y);
	if (oy < fdf->nblines - 1)
		bresenham(fdf, cx, cy, fdf->project[(oy + 1) * fdf->width + ox].x, fdf->project[(oy + 1) * fdf->width + ox].y);
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
			x2 = fdf->project[y * fdf->width + x].x;
			y2 = fdf->project[y * fdf->width + x].y;
			if (x2 >= 0 && x2 < 500 && y2 >= 0 && y2 < 500)
			{
				// put_line(fdf, x, y);
				mlx_pixel_put(fdf->mlx_ptr, fdf->window, x2, y2, 0xFF0000);
			}
		}
	}
	return (0);
}
#include <stdio.h>
t_vector2	project_point(t_fdf *fdf, int x, int y)
{
	t_vector3	v;
	t_vector3	m;

	fdf->map[y * fdf->width + x].x = x;
	fdf->map[y * fdf->width + x].y = y;
	m = fdf->map[y * fdf->width + x];
	v = vec_3_sub(fdf->map[y * fdf->width + x], fdf->cam.pos);
	
	v = mat_4_mul_v(fdf->cam.rotation, v);
	printf("m.x = %f, m.y = %f, m.z = %f\n", m.x, m.y, m.z);
	printf("v.x = %f, v.y = %f, v.z = %f\n", v.x, v.y, v.z);
	v.z += 0.0001;
	return ((t_vector2){(v.x / v.z) * W_WIDTH, (v.y / v.z) * W_HEIGHT});
}

int		calc_map(t_fdf *fdf)
{
	int	y;
	int	x;
	y = -1;
	while (++y < fdf->nblines && (x = -1))
		while (++x < fdf->width)
			fdf->project[y * fdf->width + x] = project_point(fdf, x, y);
	return (0);
}

int		key_hook(int key, t_fdf *fdf)
{
	double	speed;

	speed = 0.03;
	if (key == ROT_UP || key == ROT_DOWN)
		fdf->cam.rot_angles.x += (key == ROT_UP ? 1 : -1) * speed;
	if (key == ROT_LEFT || key == ROT_RIGHT)
		fdf->cam.rot_angles.z += (key == ROT_RIGHT ? 1 : -1) * speed;
	if (key == K_LEFT || key == K_RIGHT)
		fdf->cam.pos.x += (key == K_RIGHT ? 1 : -1) * speed;
	if (key == FORWARD || key == BACKWARD)
		fdf->cam.pos.y += (key == FORWARD ? 1 : -1) * speed;
	rotator(fdf, fdf->cam.rot_angles);
	fdf->cam.rotation = mat_4_mul(2, fdf->cam.rotation, fdf->cam.projection);
	ft_printf("rotator done%p\n",fdf);
	mlx_clear_window(fdf->mlx_ptr, fdf->window);
	ft_printf("window clear\n");
	calc_map(fdf);
	ft_printf("map calc\n");
	put_pixels(fdf);
	ft_printf("pixel put\n");
	int	i = 0;
	while (i < fdf->nblines * fdf->width)
	{
		printf("x : %f, y : %f\n", fdf->project[i].x, fdf->project[i].y);
		++i;
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
	init_matrixes(&fdf);
	ft_init_fdf(&fdf);
	rotator(&fdf, fdf.cam.rot_angles);
	calc_map(&fdf);
	int	i = 0;
	while (i < fdf.nblines * fdf.width)
	{
		printf("x : %f, y : %f\n", fdf.project[i].x, fdf.project[i].y);
		++i;
	}
	put_pixels(&fdf);
	mlx_key_hook(fdf.window, key_hook, &fdf);
	mlx_loop(fdf.mlx_ptr);
	ft_leave(ok, &fdf);
	return (0);
}
