/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:09:08 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/15 22:01:22 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <math.h>

void	ft_init_fdf(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx_ptr, fdf->w_width, fdf->w_height, "fdf");
	fdf->cam.pos.z = -20;
	fdf->cam.rot_angles.z = -M_PI;
	if (!(fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, (int)fdf->w_width, (int)fdf->w_height)))
		ft_leave(falloc, fdf);
	if (!(fdf->img.img = (int*)mlx_get_data_addr(fdf->img.img_ptr, &fdf->img.bpp, &fdf->img.stride, &fdf->img.endian)))
		ft_leave(falloc, fdf);
	init_matrixes(fdf);
	mlx_hook(fdf->window, 2, 1, key_hook, fdf);
	mlx_hook(fdf->window, 17, 0, hook_leave, fdf);
	mlx_loop_hook(fdf->mlx_ptr, draw_map, fdf);
	mlx_loop(fdf->mlx_ptr);
}
