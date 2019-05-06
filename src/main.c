/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 08:11:48 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/06 13:20:38 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

int		main(int ac, char **av)
{
	t_fdf	fdf;
	t_error	ret;

	if ((ret = open_file(ac, av, &fdf)) != ok)
		return (ft_leave(ret, &fdf));
	init_fdf(&fdf);
	int	x;
	int	y;
	x = 0;
	y = 0;
	
	while (x < 500)
	{
		++x;
		++y;
		mlx_pixel_put(fdf.mlx_ptr, fdf.window, x, y, 0xFF0000);
	}
	mlx_loop(fdf.mlx_ptr);
	while (1);
	return (0);
}
