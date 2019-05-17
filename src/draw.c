/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:02:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/17 20:28:37 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "math.h"
#include "libft.h"

t_vector2	project_point(t_fdf *fdf, int x, int y)
{
	t_vector3	v;

	v = fdf->map[y * fdf->width + x];
	v.z *= fdf->relief;
	v = vec_3_sub(v, fdf->cam.pos);
	if (!fdf->proj)
		v = mat_4_mul_v(fdf->cam.rotation, v);
	if (v.z < 0.1)
		return ((t_vector2){NAN, NAN});
	v = mat_4_mul_v(fdf->cam.projection[fdf->proj], v);
	if (!v.z)
		v.z += 1e-6;
	return ((t_vector2){(v.x + 0.25) / v.z * fdf->canvas.w_width,
			(v.y + 0.25) / v.z * fdf->canvas.w_height});
}

int			put_pixels(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fdf->height && (x = -1))
		while (++x < fdf->width)
			put_line(fdf, x, y);
	return (0);
}

int			calc_map(t_fdf *fdf)
{
	int	y;
	int	x;

	y = -1;
	while (++y < fdf->height && (x = -1))
		while (++x < fdf->width)
			fdf->project[y * fdf->width + x] = project_point(fdf, x, y);
	return (0);
}

static int	put_strings(t_fdf *fdf)
{
	char	gauge[26];

	ft_memset(gauge, '.', 25);
	gauge[25] = 0;
	gauge[0] = '-';
	gauge[24] = '+';
	gauge[1] = '[';
	gauge[23] = ']';
	gauge[((int)(fdf->relief * 10)) + 12] = '|';
	mlx_string_put(fdf->canvas.mlx_ptr, fdf->canvas.window, 1, 1, 0xFFFFFF, gauge);
	if (fdf->crea.mode)
	{
		mlx_string_put(fdf->canvas.mlx_ptr, fdf->canvas.window, 1, 20, 0xFFFFFF, ft_strjoin("x : ", ft_itoa(fdf->crea.current.x)));
		mlx_string_put(fdf->canvas.mlx_ptr, fdf->canvas.window, 1, 40, 0xFFFFFF, ft_strjoin("y : ", ft_itoa(fdf->crea.current.y)));
	}
	return (0);
}

void		put_circle(t_fdf *fdf)
{
	if (fdf->crea.mode == false)
		return ;
	int	x;
	int	y;
	int	m;
	t_vector2 v;
	v = project_point(fdf, fdf->crea.current.x, fdf->crea.current.y);

	x = 0;
	y = 10;
	m = y - 1;
	while (y >= x)
	{
		put_pixel(fdf, v.x + x, v.y + y, 110, 0xFFFF);
		put_pixel(fdf, v.x + y, v.y + x, 110, 0xFFFF);
		put_pixel(fdf, v.x - x, v.y + y, 110, 0xFFFF);
		put_pixel(fdf, v.x - y, v.y + x, 110, 0xFFFF);
		put_pixel(fdf, v.x + x, v.y - y, 110, 0xFFFF);
		put_pixel(fdf, v.x + y, v.y - x, 110, 0xFFFF);
		put_pixel(fdf, v.x - x, v.y - y, 110, 0xFFFF);
		put_pixel(fdf, v.x - y, v.y - x, 110, 0xFFFF);
		if (m >= x * 2)
		{
			m = m - 2 * x + 1;
			++x;
		}
		else if (m < 2 * (10 - y))
		{
			m = m + 2 * y - 1;
			--y;
		}
		else
		{
			m = m + 2 * (y - x - 1);
			--y;
			++x;
		}
	}
}

int			draw_map(t_fdf *fdf)
{
	calc_map(fdf);
	ft_bzero(fdf->canvas.img.img, (int)fdf->canvas.w_width * (int)fdf->canvas.w_height * sizeof(int));
	put_pixels(fdf);
	put_circle(fdf);
	mlx_put_image_to_window(fdf->canvas.mlx_ptr, fdf->canvas.window, fdf->canvas.img.img_ptr, 0, 0);
	put_strings(fdf);
	return (0);
}
