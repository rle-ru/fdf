/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 06:02:59 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:03:00 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x_to_str(va_list *args, t_info *info)
{
	long	num;

	info->flags &= (BLANK ^ CHAR_MAX);
	info->flags &= (PLUS ^ CHAR_MAX);
	if (info->sub_specifier == 'j')
		return (ft_ltoabc(va_arg(*args, intmax_t), 16, 'a'));
	else if (info->sub_specifier == 'H')
		num = (char)va_arg(*args, int);
	else if (info->sub_specifier == 'h')
		num = (int)va_arg(*args, int);
	else if (info->sub_specifier == 'l')
		num = va_arg(*args, long);
	else
		num = va_arg(*args, int);
	return (ft_ltoabc(num, 16, 'a'));
}

char	*xu_to_str(va_list *args, t_info *info)
{
	long	num;

	info->flags &= (BLANK ^ CHAR_MAX);
	info->flags &= (PLUS ^ CHAR_MAX);
	if (info->sub_specifier == 'j')
		return (ft_ltoabc(va_arg(*args, intmax_t), 16, 'A'));
	else if (info->sub_specifier == 'H')
		num = (char)va_arg(*args, int);
	else if (info->sub_specifier == 'h')
		num = (int)va_arg(*args, int);
	else if (info->sub_specifier == 'l')
		num = va_arg(*args, long);
	else
		num = va_arg(*args, int);
	return (ft_ltoabc(num, 16, 'A'));
}

char	*o_to_str(va_list *args, t_info *info)
{
	long	num;

	info->flags &= (BLANK ^ CHAR_MAX);
	info->flags &= (PLUS ^ CHAR_MAX);
	if (info->sub_specifier == 'j')
		return (ft_ltoabc(va_arg(*args, intmax_t), 8, 'a'));
	else if (info->sub_specifier == 'H')
		num = (char)va_arg(*args, int);
	else if (info->sub_specifier == 'h')
		num = (int)va_arg(*args, int);
	else if (info->sub_specifier == 'l')
		num = va_arg(*args, long);
	else
		num = va_arg(*args, int);
	return (ft_ltoabc(num, 8, 'a'));
}

char	*b_to_str(va_list *args, t_info *info)
{
	info->flags &= (BLANK ^ CHAR_MAX);
	info->flags &= (PLUS ^ CHAR_MAX);
	if (info->sub_specifier == 'j')
		return (ft_ltoabc(va_arg(*args, intmax_t), 2, 'a'));
	if (info->sub_specifier == 'l')
		return (ft_ltoabc(va_arg(*args, long), 2, 'A'));
	else
		return (ft_ltoabc(va_arg(*args, int), 2, 'A'));
}

char	*p_to_str(va_list *args, t_info *info)
{
	info->flags &= (BLANK ^ CHAR_MAX);
	info->flags &= (PLUS ^ CHAR_MAX);
	info->flags |= TAGL;
	return (ft_ltoabc(va_arg(*args, long), 16, 'a'));
}
