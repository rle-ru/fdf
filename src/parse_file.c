/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:06:33 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:34:13 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static t_error	ft_check_line(t_fdf *fdf, char *line)
{
	t_line		*new;

	if (!(new = malloc(sizeof(t_line))))
		return (falloc);
	if (fdf->parser.last_line == NULL)
		fdf->parser.lines = new;
	else
		fdf->parser.last_line->next = new;
	fdf->parser.last_line = new;
	new->line = line;
	new->next = NULL;
	if ((new->nbx = ft_countwords(line, ' ')) == 0
			|| new->nbx != fdf->parser.lines->nbx)
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
	while ((ret_gnl = get_next_line(fdf->parser.fd, &line)) == 1)
	{
		++fdf->height;
		if ((ret = ft_check_line(fdf, line)) != ok)
			return (ret);
	}
	if (ret_gnl == -1)
		return (falloc);
	if (fdf->parser.lines == NULL)
		return (badline);
	if ((ret = ft_create_map(fdf)) != ok)
		return (ret);
	fdf->parser.lines = NULL;
	close(fdf->parser.fd);
	return (ok);
}
