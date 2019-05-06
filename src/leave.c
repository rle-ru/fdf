/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:01:44 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/06 18:42:07 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void		ft_usage(void)
{
	ft_printf("Usage :   ./fdf map\n");
}

static void		ft_print_error(t_error ret, t_fdf *fdf)
{
	if (ret == usage)
		ft_usage();
	else if (ret == filepath)
		ft_printf("Invalid file \"%s\"\n", fdf->fname);
	else if (ret == falloc)
		ft_printf("A malloc failed (dafuk ?)");
	else if (ret == badline)
		ft_printf("Incorrect line : %d\n", fdf->nblines);
}

static void		ft_clear(t_fdf *fdf)
{
	free_lines(fdf);
	ft_memdel((void**)&fdf->map);
}

int				ft_leave(t_error ret, t_fdf *fdf)
{
	ft_print_error(ret, fdf);
	ft_clear(fdf);
	return (0);
}
