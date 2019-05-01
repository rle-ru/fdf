/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 08:11:48 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 09:12:41 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"

int		main(int ac, char **av)
{
	void	*mlx;
	void	*window;

	(void)ac;
	(void)av;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 500, 500, "yolo");
	int	x;
	int	y;
	x = 0;
	y = 0;
	while (x < 500)
	{
		++x;
		++y;
		mlx_pixel_put(mlx, window, x, y, 0x00FF0000);
	}
	while (1);
	return (0);
}
