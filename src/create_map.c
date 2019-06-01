/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:06:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/01 16:41:58 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

static t_error	set_colors(t_fdf *fdf)
{
	int		i;

	i = fdf->width * fdf->height;
	while (i--)
	{
		if (!fdf->map[i].color)
			select_color(fdf, i);
	}
	return (ok);
}

static void		ft_split_line2(t_fdf *fdf, int x, int y)
{
	fdf->map[y * fdf->width + x].y = y;
	fdf->map[y * fdf->width + x].x = x;
	if (-fdf->map[y * fdf->width + x].z > fdf->parser.maxz)
		fdf->parser.maxz = -fdf->map[y * fdf->width + x].z;
	if (-fdf->map[y * fdf->width + x].z < fdf->parser.minz)
		fdf->parser.minz = -fdf->map[y * fdf->width + x].z;
}

static void		ft_split_line(t_fdf *fdf, int y, t_line *line)
{
	int		x;
	int		lpos;

	x = -1;
	lpos = 0;
	while (++x < fdf->width)
	{
		while (line->line[lpos] && line->line[lpos] == ' ')
			++lpos;
		fdf->map[y * fdf->width + x].z = -ft_atoi(line->line + lpos);
		ft_split_line2(fdf, x, y);
		while (line->line[lpos] && (ft_isdigit(line->line[lpos])
			|| line->line[lpos] == '-'))
			++lpos;
		if (line->line[lpos] == ',' && line->line[lpos + 1]
			&& line->line[lpos + 2])
		{
			fdf->map[y * fdf->width + x].color = ft_atoi_base(&line->line[lpos
				+ 3], 16);
			while (line->line[lpos] && line->line[lpos] != ' ')
				++lpos;
		}
	}
}

static void		ft_window_size(t_fdf *fdf)
{
	if (fdf->width < 20 && fdf->height < 20)
	{
		fdf->canvas.w_height = 750;
		fdf->canvas.w_width = 1000;
	}
	else if (fdf->width < 50 && fdf->height < 50)
	{
		fdf->canvas.w_height = 1000;
		fdf->canvas.w_width = 1500;
	}
	else if (fdf->width < 100 && fdf->height < 100)
	{
		fdf->canvas.w_height = 1200;
		fdf->canvas.w_width = 2000;
	}
	else
	{
		fdf->canvas.w_height = 1440;
		fdf->canvas.w_width = 2560;
	}
}

t_error			ft_create_map(t_fdf *fdf)
{
	int		y;
	t_line	*line;
	t_line	*tmp;

	y = -1;
	fdf->width = fdf->parser.lines->nbx;
	fdf->parser.maxz = INT_MIN;
	fdf->parser.minz = INT_MAX;
	if (!(fdf->map = ft_memalloc(sizeof(t_vector3) * fdf->height * fdf->width)))
		return (falloc);
	if (!(fdf->project = malloc(sizeof(t_vector2) * fdf->height * fdf->width)))
		return (falloc);
	ft_window_size(fdf);
	line = fdf->parser.lines;
	while (++y < fdf->height && line != NULL)
	{
		ft_split_line(fdf, y, line);
		tmp = line;
		line = line->next;
		free(tmp->line);
		free(tmp);
	}
	return (set_colors(fdf));
}
