/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:50:33 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/06 17:52:13 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

void	free_lines(t_fdf *fdf)
{
	int		i;

	i = 0;
	if (fdf->lines)
		while (i < fdf->nblines)
			free(fdf->lines[i++].line);
	ft_memdel((void**)&fdf->lines);
}
