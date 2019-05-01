/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 08:27:06 by rle-ru            #+#    #+#             */
/*   Updated: 2018/12/04 14:21:06 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_fdprintf(int fd, const char *format, ...)
{
	int				count;
	va_list			args;
	char			*output;
	t_translater	*table;

	table = create_table();
	va_start(args, format);
	count = 0;
	output = record_string((char *)format, &args, table);
	ft_putstr_fd(output, fd);
	count = ft_strlen(output);
	ft_strdel(&output);
	va_end(args);
	free(table);
	return (count);
}

int				ft_printf(const char *format, ...)
{
	int				count;
	va_list			args;
	char			*output;
	t_translater	*table;

	table = create_table();
	va_start(args, format);
	count = 0;
	output = record_string((char *)format, &args, table);
	ft_putstr(output);
	count = ft_strlen(output);
	ft_strdel(&output);
	va_end(args);
	free(table);
	return (count);
}
