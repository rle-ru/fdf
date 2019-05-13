/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:01:44 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/13 22:35:26 by rle-ru           ###   ########.fr       */
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
	if (fdf->lines)
		free_lines(fdf);
	ft_memdel((void**)&fdf->map);
	if (fdf->window)
		mlx_destroy_window(fdf->mlx_ptr, fdf->window);
	if (fdf->img.img_ptr)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.img_ptr);
}

int				ft_leave(t_error ret, t_fdf *fdf)
{
	ft_print_error(ret, fdf);
	ft_clear(fdf);
	exit(0);
	return (0);
}

int				hook_leave(t_fdf *fdf)
{
	ft_leave(ok, fdf);
	return (0);
}
