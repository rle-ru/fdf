/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 08:11:48 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/07 13:13:24 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h" //
#include "fdf.h"

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
	/*
	**	mlx tests
	*/
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
	ft_leave(ok, &fdf);
	return (0);
}
