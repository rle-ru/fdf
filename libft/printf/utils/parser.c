/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:17:22 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:04:39 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_info	*parser(char *string, va_list *args)
{
	t_info	*info;
	char	*start;
	char	**cursor;

	cursor = &string;
	start = string;
	(*cursor)++;
	if (!(info = (t_info *)ft_memalloc(sizeof(t_info))))
		return (0);
	get_flags(cursor, info);
	get_width(cursor, info, args);
	get_precision(cursor, info, args);
	get_sub_specifier(cursor, info);
	get_specifier(cursor, info);
	info->size = *cursor - start;
	return (info);
}
