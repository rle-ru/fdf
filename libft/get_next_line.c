/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:21:11 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:30:14 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

static char		*gnl_strnjoinfree(char *s1, char *s2, size_t n)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strcpy(ret, s1);
	ft_strncat(ret, s2, n);
	free(s1);
	return (ret);
}

static int		end_gnl(char **line)
{
	if (!**line)
	{
		ft_strdel(line);
		return (0);
	}
	else
		return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	str[4096][BUFF_SIZE + 1];
	char		*buf;
	char		*cur;
	int			ret;

	buf = str[fd];
	if (fd < 0 || fd > 4095 || read(fd, buf, 0) < 0 || !line
			|| BUFF_SIZE < 1 || !(*line = ft_strnew(0)))
		return (-1);
	while (1)
	{
		if ((cur = ft_strchr(buf, 10)))
		{
			if (!(*line = gnl_strnjoinfree(*line, buf, cur - buf)))
				return (-1);
			ft_strncpy(buf, &buf[cur - buf + 1], BUFF_SIZE - (cur - buf));
			return (1);
		}
		if (!(*line = gnl_strnjoinfree(*line, buf, BUFF_SIZE)))
			return (-1);
		ret = read(fd, str[fd], BUFF_SIZE);
		buf[ret] = '\0';
		if (!ret)
			return (end_gnl(line));
	}
}
