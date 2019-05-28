/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:55:13 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:04:04 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*uint_to_str(va_list *args, t_info *info)
{
	long	num;

	info->flags &= (BLANK ^ CHAR_MAX);
	info->flags &= (PLUS ^ CHAR_MAX);
	if (info->sub_specifier == 'H')
		num = (char)va_arg(*args, int);
	else if (info->sub_specifier == 'h')
		num = (int)va_arg(*args, int);
	else if (info->sub_specifier == 'l' || info->specifier == 'U')
		num = va_arg(*args, long);
	else
		num = va_arg(*args, int);
	return (ft_ltoabc(num, 10, 'a'));
}
