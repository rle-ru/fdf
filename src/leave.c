/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:01:44 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/07 10:05:51 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

static void		ft_usage(void)
{
	ft_fdprintf(STDERR_FILENO, "Usage :   ./fdf <map>\n");
}

static void		ft_print_error(t_error ret, t_fdf *fdf)
{
	if (ret == usage)
		ft_usage();
	else if (ret == filepath)
		ft_fdprintf(STDERR_FILENO, "Invalid file \"%s\"\n", fdf->fname);
	else if (ret == falloc)
		ft_fdprintf(STDERR_FILENO, "A malloc failed (dafuk ?)");
	else if (ret == badline)
		ft_fdprintf(STDERR_FILENO, "Incorrect line : %d\n", fdf->nblines);
}

static void		ft_clear(t_fdf *fdf)
{
	free_lines(fdf);
	ft_memdel((void**)&fdf->map);
	mlx_destroy_window(fdf->mlx_ptr, fdf->window);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img);
}

void			ft_leave(t_error ret, t_fdf *fdf)
{
	ft_print_error(ret, fdf);
	ft_clear(fdf);
	exit (0);
}
