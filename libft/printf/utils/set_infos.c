/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:36:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/01 00:00:02 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_zero_width(t_info *info)
{
	int		length;
	char	*new;
	char	*old;

	if (!(info->flags & ZERO) || info->precision != -1)
		return ;
	if (info->flags & (PLUS + ISNEG + BLANK) && info->width > 0)
		info->width--;
	length = ft_strlen(info->result);
	if (info->width <= length)
		return ;
	old = info->result;
	new = ft_strnew(info->width);
	ft_memset(
		info->flags & JUSTIFY ? new + length : new, '0', info->width - length);
	info->result = info->flags & JUSTIFY
		? ft_strcpy(new, info->result)
		: ft_strcat(new, info->result);
	if ((info->flags & TAG) && (info->flags & ZERO)
			&& ft_strchr("xX", info->specifier))
		info->result[1] = info->flags * TAGL ? 'x' : 'X';
	if (info->flags & JUSTIFY)
		info->result[length] = ' ';
	ft_strdel(&old);
}

void		set_width(t_info *info)
{
	int		length;
	char	*new;
	char	*old;

	length = ft_strlen(info->result);
	if (info->width <= length)
		return ;
	old = info->result;
	new = ft_strnew(info->width);
	ft_memset(
		info->flags & JUSTIFY ? new + length : new,
		info->flags & ZERO && info->precision == -1 ? '0' : ' ',
		info->width - length);
	info->result = info->flags & JUSTIFY
		? ft_strcpy(new, info->result)
		: ft_strcat(new, info->result);
	if ((info->flags & TAG) && (info->flags & ZERO)
			&& ft_strchr("xX", info->specifier))
		info->result[1] = info->flags * TAGL ? 'x' : 'X';
	if (info->flags & JUSTIFY)
		info->result[length] = ' ';
	ft_strdel(&old);
}

void		set_to_precision(t_info *info)
{
	char	*new;
	char	*old;
	int		length;

	if (info->precision == -1)
		return ;
	length = ft_strlen(info->result);
	if (info->specifier == 's' && info->precision < length)
		(info->result)[info->precision] = 0;
	if (ft_strchr("idDxXoObup", info->specifier) && info->precision > length)
	{
		new = ft_strnew(info->precision);
		old = info->result;
		ft_memset(new, '0', info->precision - length);
		info->result = ft_strcat(new, info->result);
		ft_strdel(&old);
	}
	if (info->precision == 0 && info->result[0] == '0')
		info->result[0] = 0;
}

void		set_flags(t_info *info)
{
	if (info->flags & ISNEG)
		info->result = ft_strjoin_free("-", info->result, RIGHT);
	else if (info->flags & PLUS)
		info->result = ft_strjoin_free("+", info->result, RIGHT);
	else if (info->flags & BLANK && info->specifier != '%')
		info->result = ft_strjoin_free(" ", info->result, RIGHT);
	else if (info->flags & TAG && info->specifier == 'o'
			&& info->result[0] != '0')
		info->result = ft_strjoin_free("0", info->result, RIGHT);
	else if (info->flags & TAGL && info->result[0] != '\0'
			&& info->result[0] != '0' && (info->flags & ZERO) == 0
			&& (info->specifier == 'x' || info->specifier == 'p'))
		info->result = ft_strjoin_free("0x", info->result, RIGHT);
	else if (info->flags & TAGU && info->specifier == 'X'
			&& info->result[0] != '0' && info->result[0] != '\0'
			&& (info->flags & ZERO) == 0)
		info->result = ft_strjoin_free("0X", info->result, RIGHT);
	else if (info->flags & TAGL && info->specifier == 'p'
			&& info->result[0] == '0')
		info->result = ft_strjoin_free("0x", info->result, RIGHT);
}
