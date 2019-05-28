/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:26:27 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 18:38:32 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(char **cursor, t_info *info)
{
	char	c;

	info->flags = 0;
	while (1)
	{
		c = **cursor;
		if (c == '-')
			info->flags |= JUSTIFY;
		else if (c == '0' && !(info->flags & JUSTIFY))
			info->flags |= ZERO;
		else if (c == '+')
			info->flags |= PLUS;
		else if (c == ' ')
			info->flags |= BLANK;
		else if (c == '#')
			info->flags |= TAG;
		else
			break ;
		(*cursor)++;
	}
}

void	get_width(char **cursor, t_info *info, va_list *args)
{
	if (ft_isdigit(**cursor))
	{
		info->width = ft_atoi((const char *)*cursor);
		while (ft_isdigit(**cursor))
			(*cursor)++;
	}
	if (**cursor == '*')
	{
		info->width = va_arg(*args, int);
		if (info->width < 0)
		{
			info->width = -(info->width);
			info->flags |= JUSTIFY;
		}
		(*cursor)++;
	}
}

void	get_precision(char **cursor, t_info *info, va_list *args)
{
	if (**cursor != '.')
	{
		info->precision = -1;
		return ;
	}
	(*cursor)++;
	if (!(ft_isdigit(**cursor)) && **cursor != '*')
	{
		info->precision = 0;
		return ;
	}
	if (**cursor == '*')
	{
		info->precision = va_arg(*args, int);
		info->precision = info->precision < 0 ? -1 : info->precision;
	}
	else
		info->precision = ft_atoi(*cursor);
	while (**cursor && (ft_isdigit(**cursor) || **cursor == '*'))
		(*cursor)++;
}

void	get_specifier(char **cursor, t_info *info)
{
	info->specifier = **cursor;
	if (info->specifier == 'x' && info->flags & TAG)
		info->flags |= TAGL;
	if (info->specifier == 'X' && info->flags & TAG)
		info->flags |= TAGU;
	(*cursor)++;
}

void	get_sub_specifier(char **cursor, t_info *info)
{
	if (**cursor == 'l')
	{
		info->sub_specifier = 'l';
		(*cursor) += *(*cursor + 1) == 'l' ? 1 : 0;
	}
	else if (**cursor == 'h' && *(*cursor + 1) == 'h')
	{
		info->sub_specifier = 'H';
		(*cursor)++;
	}
	else if (**cursor == 'h')
		info->sub_specifier = 'h';
	else if (**cursor == 'L')
		info->sub_specifier = 'L';
	else if (**cursor == 'j')
		info->sub_specifier = 'j';
	else
		info->sub_specifier = 0;
	if (info->sub_specifier)
		(*cursor)++;
	while (ft_strchr("hlL", **cursor))
		(*cursor)++;
}
