/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 08:11:48 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/10 09:32:16 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	int	i;

	i = 0;
	// while (i < fdf.width * fdf.nblines)
	// {
	// 	t_vector3	v = fdf.map[i];
	// 	ft_printf("%03f %03f  %03f\n", v.x, v.y, v.z);
	// 	++i;
	// }
	ft_init_fdf(&fdf);
	// int	i = 0;
	// while (i < fdf.nblines * fdf.width)
	// {
	// 	printf("x : %f, y : %f\n", fdf.project[i].x, fdf.project[i].y);
	// 	++i;
	// }
	ft_leave(ok, &fdf);
	return (0);
}
