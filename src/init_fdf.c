/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:09:08 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/10 13:39:49 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

void	ft_init_fdf(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx_ptr, W_WIDTH, W_HEIGHT, "fdf");
	fdf->cam.pos.z = -20;
	// fdf->cam.pos.x = -30;
	// fdf->cam.pos.y = -30;
	init_matrixes(fdf);
	
	// draw_map(fdf);
	mlx_hook(fdf->window, 2, 1, key_hook, fdf);
	mlx_hook(fdf->window, 17, 0, hook_leave, fdf);
	mlx_loop_hook(fdf->mlx_ptr, draw_map, fdf);
	mlx_loop(fdf->mlx_ptr);
}
