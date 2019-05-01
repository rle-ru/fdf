/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute_floats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:19:42 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/29 16:38:51 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*distribute_floats(va_list *args, t_info *info)
{
	return (info->sub_specifier == 'L'
		? longdouble_to_str(args, info)
		: float_to_str(args, info));
}
