/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:06:33 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/07 10:05:21 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static t_error	ft_realloc(t_fdf *fdf)
{
	t_line	*new;

	if (fdf->nblines < fdf->lines_capacity)
		return (ok);
	if (fdf->lines_capacity == 0)
		fdf->lines_capacity = 16;
	else
		fdf->lines_capacity *= 2;
	if (!(new = malloc(sizeof(t_line) * fdf->lines_capacity)))
		return (falloc);
	if (fdf->lines != NULL)
		ft_memcpy(new, fdf->lines, sizeof(t_line) * fdf->nblines - 1);
	free(fdf->lines);
	fdf->lines = new;
	return (ok);
}

static t_error	ft_check_line(t_fdf *fdf, char *line)
{
	if (ft_realloc(fdf) != ok)
	{
		free(line);
		return (falloc);
	}
	fdf->lines[fdf->nblines - 1].line = line;
	if ((fdf->lines[fdf->nblines - 1].nbx = ft_countwords(line, ' ')) == 0)
		return (badline);
	if (fdf->lines[fdf->nblines - 1].nbx != fdf->lines[0].nbx)
		return (badline);
	return (ok);
}

t_error			ft_parse_file(t_fdf *fdf)
{
	int		ret_gnl;
	char	*line;
	int		current_lines;
	t_error	ret;

	current_lines = 0;
	while ((ret_gnl = get_next_line(fdf->fd, &line)) == 1)
	{
		++fdf->nblines;
		if ((ret = ft_check_line(fdf, line)) != ok)
			return (ret);
	}
	if (ret_gnl == -1)
		return (falloc);
	if ((ret = ft_create_map(fdf)) != ok)
		return (ret);
	free_lines(fdf);
	close(fdf->fd);
	return (ok);
}
