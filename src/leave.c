/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:01:44 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/06 13:39:03 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void		ft_usage(void)
{
	ft_printf("Usage :   ./fdf map\n");
}

static void		ft_print_error(t_error ret, char *fname)
{
	if (ret == usage)
		ft_usage();
	if (ret == filepath)
		ft_printf("Invalid file \"%s\"\n", fname);
	if (ret == falloc)
		ft_printf("A malloc failed (dafuk ?)");
}

static void		ft_clear(t_fdf *fdf)
{
	(void)fdf;
}

int				ft_leave(t_error ret, t_fdf *fdf)
{
	ft_print_error(ret, fdf->fname);
	ft_clear(fdf);
	return (0);
}
