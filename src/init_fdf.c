/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:09:08 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/14 11:47:45 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <math.h>
 // add malloc error 
void	ft_init_fdf(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx_ptr, W_WIDTH, W_HEIGHT, "fdf");
	fdf->cam.pos.z = -20;
	fdf->cam.rot_angles.z = -M_PI;
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, 500, 500);
	fdf->img.img = (int*)mlx_get_data_addr(fdf->img.img_ptr, &fdf->img.bpp, &fdf->img.stride, &fdf->img.endian);
	// fdf->img.bpp /= 8;
	init_matrixes(fdf);
	mlx_hook(fdf->window, 2, 1, key_hook, fdf);
	mlx_hook(fdf->window, 17, 0, hook_leave, fdf);
	mlx_loop_hook(fdf->mlx_ptr, draw_map, fdf);
	mlx_loop(fdf->mlx_ptr);
}
