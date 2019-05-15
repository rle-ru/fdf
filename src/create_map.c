/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:06:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/15 22:22:36 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

static void		set_colors(t_fdf *fdf)
{
	int	i;

	i = fdf->width  * fdf->height;
	while (i--)
	{
		if (-fdf->map[i].z < 0)
			fdf->map[i].color = get_color(C_DEEP, C_GROUND, get_gradient(-fdf->map[i].z,
				fdf->parser.minz, 0));
		else if (-fdf->map[i].z > 0)
			fdf->map[i].color = get_color(C_GROUND, C_SUMMIT, get_gradient(-fdf->map[i].z,
				0, fdf->parser.maxz));
		else
			fdf->map[i].color = C_GROUND;
	}
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
		fdf->map[y * fdf->width + x].y = y;
		fdf->map[y * fdf->width + x].x = x;
		if (-fdf->map[y * fdf->width + x].z > fdf->parser.maxz)
			fdf->parser.maxz = -fdf->map[y * fdf->width + x].z;
		if (-fdf->map[y * fdf->width + x].z < fdf->parser.minz)
			fdf->parser.minz = -fdf->map[y * fdf->width + x].z;
		while (line->line[lpos]
				&& (ft_isdigit(line->line[lpos])
					|| line->line[lpos] == '-'))
			++lpos;
	}
}

static void		ft_window_size(t_fdf *fdf)
{
	if (fdf->width < 20 && fdf->height < 20)
	{
		fdf->canvas.w_height = 500;
		fdf->canvas.w_width = 500;
	}
	else if (fdf->width < 50 && fdf->height < 50)
	{
		fdf->canvas.w_height = 750;
		fdf->canvas.w_width = 1000;
	}
	else if (fdf->width < 100 && fdf->height < 100)
	{
		fdf->canvas.w_height = 1000;
		fdf->canvas.w_width = 1750;
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
	if (!(fdf->map = malloc(sizeof(t_vector3)
				* fdf->height * fdf->width)))
		return (falloc);
	if (!(fdf->project = malloc(sizeof(t_vector2)
				* fdf->height * fdf->width)))
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
	set_colors(fdf);
	return (ok);
}
