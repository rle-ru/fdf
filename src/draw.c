/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:02:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/17 15:06:42 by dacuvill         ###   ########.fr       */
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

int			draw_map(t_fdf *fdf)
{
	calc_map(fdf);
	ft_bzero(fdf->canvas.img.img, (int)fdf->canvas.w_width * (int)fdf->canvas.w_height * sizeof(int));
	put_pixels(fdf);
	mlx_put_image_to_window(fdf->canvas.mlx_ptr, fdf->canvas.window, fdf->canvas.img.img_ptr, 0, 0);
	return (0);
}
