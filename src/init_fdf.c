/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:09:08 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/14 18:33:54 by dacuvill         ###   ########.fr       */
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
	ft_printf("Width : %f\nHeight : %f\n", fdf->w_width, fdf->w_height);
	fdf->window = mlx_new_window(fdf->mlx_ptr, fdf->w_width, fdf->w_height, "fdf");
	fdf->cam.pos.z = -20;
	fdf->cam.rot_angles.z = -M_PI;
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, (int)fdf->w_width, (int)fdf->w_height);
	fdf->img.img = (int*)mlx_get_data_addr(fdf->img.img_ptr, &fdf->img.bpp, &fdf->img.stride, &fdf->img.endian);
	// fdf->img.bpp /= 8;
	init_matrixes(fdf);
	mlx_hook(fdf->window, 2, 1, key_hook, fdf);
	mlx_hook(fdf->window, 17, 0, hook_leave, fdf);
	mlx_loop_hook(fdf->mlx_ptr, draw_map, fdf);
	mlx_loop(fdf->mlx_ptr);
}
