/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:06:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/13 15:53:39 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

static void		set_colors(t_fdf *fdf)
{
	int	i;

	i = fdf->width  * fdf->nblines;
	while (i--)
	{
		if (fdf->map[i].z < 0)
			fdf->map[i].color = get_color(C_GROUND, C_SUMMIT,
					-fdf->map[i].z * 100 / fdf->maxz);
		else
			fdf->map[i].color = get_color(C_GROUND, C_DEEP,
					-fdf->map[i].z * 100 / fdf->minz);
	}
}

static void		ft_split_line(t_fdf *fdf, int y, t_line *line)
{
	int		x;
	int		lpos;

	x = -1;
	lpos = 0;
	fdf->maxz = INT_MIN;
	fdf->minz = INT_MAX;
	while (++x < fdf->width)
	{
		while (line->line[lpos] && line->line[lpos] == ' ')
			++lpos;
		fdf->map[y * fdf->width + x].z = -ft_atoi(line->line + lpos);
		fdf->map[y * fdf->width + x].y = y;
		fdf->map[y * fdf->width + x].x = x;
		if (fdf->map[y * fdf->width + x].z > fdf->maxz)
			fdf->maxz = fdf->map[y * fdf->width + x].z;
		else if (fdf->map[y * fdf->width + x].z < fdf->minz)
			fdf->minz = fdf->map[y * fdf->width + x].z;
		while (line->line[lpos]
				&& (ft_isdigit(line->line[lpos])
					|| line->line[lpos] == '-'))
			++lpos;
	}
}

t_error			ft_create_map(t_fdf *fdf)
{
	int		y;
	t_line	*line;
	t_line	*tmp;

	y = -1;
	if (!(fdf->map = malloc(sizeof(t_vector3)
				* fdf->nblines * fdf->lines->nbx)))
		return (falloc);
	if (!(fdf->project = malloc(sizeof(t_vector2)
				* fdf->nblines * fdf->lines->nbx)))
		return (falloc);
	fdf->width = fdf->lines->nbx;
	line = fdf->lines;
	while (++y < fdf->nblines && line != NULL)
	{
		ft_split_line(fdf, y, line);
		tmp = line;
		line = line->next;
		free(tmp->line);
		free(tmp);
	}
	set_colors(fdf);
	return (ok);
}
