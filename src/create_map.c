/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:06:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/07 13:02:02 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static void		ft_split_line(t_fdf *fdf, int i, t_line *line)
{
	int		j;
	int		k;
	int		lpos;

	k = 0;
	lpos = 0;
	j = i * fdf->lines->nbx;
	while (k < line->nbx)
	{
		while (line->line[lpos] && line->line[lpos] == ' ')
			++lpos;
		fdf->map[j] = ft_atoi(line->line + lpos);
		while (line->line[lpos]
				&& (ft_isdigit(line->line[lpos])
					|| line->line[lpos] == '-'))
			++lpos;
		++k;
		++j;
	}
}

t_error			ft_create_map(t_fdf *fdf)
{
	int		i;
	int		j;
	t_line	*line;

	i = 0;
	j = 0;
	if (!(fdf->map = malloc(sizeof(int) * fdf->nblines * fdf->lines->nbx)))
		return (falloc);
	line = fdf->lines;
	while (i < fdf->nblines && line != NULL)
	{
		ft_split_line(fdf, i, line);
		++i;
		line = line->next;
	}
	i = 0;
	return (ok);
}
