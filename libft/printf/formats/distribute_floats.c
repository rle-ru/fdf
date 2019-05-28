/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_floats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:19:42 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:03:23 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*distribute_floats(va_list *args, t_info *info)
{
	return (info->sub_specifier == 'L'
		? longdouble_to_str(args, info)
		: float_to_str(args, info));
}
