/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:53:02 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/06 14:08:27 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

t_error	ft_open_file(int ac, char **av, t_fdf *fdf)
{
	if (ac == 1)
		return (usage);
	if ((fdf->fd = open(av[1], O_RDONLY)) == -1)
	{
		fdf->fname = av[1];
		return (filepath);
	}
	return (ok);
}
