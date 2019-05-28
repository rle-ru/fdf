/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:53:02 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:52:01 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

t_error	ft_open_file(int ac, char **av, t_fdf *fdf)
{
	if (ac == 1)
		return (usage);
	if (!ft_strcmp(av[1], "/dev/zero"))
		return (filepath);
	if ((fdf->parser.fd = open(av[1], O_RDONLY)) == -1)
	{
		fdf->parser.fname = av[1];
		return (filepath);
	}
	return (ok);
}
