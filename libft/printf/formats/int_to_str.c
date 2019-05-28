/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:03:16 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:03:44 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*int_to_str(va_list *args, t_info *info)
{
	long	num;

	if (info->sub_specifier == 'j')
		return (ft_ltoabc(va_arg(*args, intmax_t), 10, 'a'));
	else if (info->sub_specifier == 'H')
		num = (char)va_arg(*args, int);
	else if (info->sub_specifier == 'h')
		num = (int)va_arg(*args, int);
	else if (info->sub_specifier == 'l' || info->specifier == 'D')
	{
		num = va_arg(*args, long);
		if (num == LONG_MIN)
			return (ft_strdup("-9223372036854775808"));
	}
	else
		num = va_arg(*args, int);
	if (num < 0)
	{
		num *= -1;
		info->flags |= ISNEG;
	}
	return (ft_ltoabc(num, 10, 'a'));
}
