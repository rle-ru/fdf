/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:06:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/06 21:00:32 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void		ft_split_line(t_fdf *fdf, int i)
{
	int		j;
	int		k;
	int		lpos;

	k = 0;
	lpos = 0;
	j = i * fdf->lines[0].nbx;
	while (k < fdf->lines[0].nbx)
	{
		while (fdf->lines[i].line[lpos] && fdf->lines[i].line[lpos] == ' ')
			++lpos;
		fdf->map[j] = ft_atoi(fdf->lines[i].line + lpos);
		while (fdf->lines[i].line[lpos]
				&& (ft_isdigit(fdf->lines[i].line[lpos])
					|| fdf->lines[i].line[lpos] == '-'))
			++lpos;
		++k;
		++j;
	}
}

t_error			ft_create_map(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(fdf->map = malloc(sizeof(int) * fdf->nblines * fdf->lines[0].nbx)))
		return (falloc);
	while (i < fdf->nblines)
	{
		ft_split_line(fdf, i);
		fdf->map[j] = ft_atoi(fdf->lines[i].line);
		++i;
	}
	i = 0;
	return (ok);
}
