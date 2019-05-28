/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longdouble_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:43:52 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:03:51 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prefix_zeros(char *original_result, int zeros)
{
	char	*new_string;
	int		original_result_len;

	original_result_len = ft_strlen(original_result);
	new_string = ft_strnew(original_result_len + zeros);
	ft_strcpy(new_string, original_result);
	ft_memdel((void **)&original_result);
	ft_memset(new_string + original_result_len, '0', zeros);
	return (new_string);
}

static void	check_negative(long double *input, t_info *info)
{
	if (*input < 0.0)
	{
		info->flags |= ISNEG;
		*input *= -1;
	}
}

char		*longdouble_to_str(va_list *args, t_info *info)
{
	long double	input;
	long		int_part;
	long double	floating_part;
	char		*result;
	char		*flt_tmp;

	if (info->precision == -1)
		info->precision = 6;
	input = va_arg(*args, long double);
	input += 5.0L / ft_pow(10, info->precision + 1);
	check_negative(&input, info);
	int_part = (long)input;
	floating_part = input - (long double)int_part;
	result = ft_itoa(int_part);
	if (info->precision > 0)
	{
		result = ft_strjoin_free(result, ".", LEFT);
		flt_tmp = ft_ltoa(
			(long)(floating_part * ft_pow(10l, info->precision)));
		if ((int)ft_strlen(flt_tmp) < info->precision)
			result = prefix_zeros(result, info->precision - ft_strlen(flt_tmp));
		result = ft_strjoin_free(result, flt_tmp, LEFT + RIGHT);
	}
	return (result);
}
