/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:43:52 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/03 14:18:49 by bwaterlo         ###   ########.fr       */
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

static void	check_negative(double *input, t_info *info)
{
	if (*input < 0.0)
	{
		info->flags |= ISNEG;
		*input *= -1;
	}
}

char		*float_to_str(va_list *args, t_info *info)
{
	double	input;
	long	int_part;
	double	floating_part;
	char	*result;
	char	*flt_tmp;

	if (info->precision == -1)
		info->precision = 6;
	input = va_arg(*args, double);
	input += (double)5.0 / ft_pow(10, info->precision + 1);
	check_negative(&input, info);
	int_part = (long)input;
	floating_part = input - (double)int_part;
	result = ft_itoa(int_part);
	if (info->precision > 0)
	{
		result = ft_strjoin_free(result, ".", LEFT);
		flt_tmp = ft_ltoa((long)(floating_part * ft_pow(10l, info->precision)));
		if ((int)ft_strlen(flt_tmp) < info->precision)
			result = prefix_zeros(result, info->precision - ft_strlen(flt_tmp));
		result = ft_strjoin_free(result, flt_tmp, LEFT + RIGHT);
	}
	return (result);
}
