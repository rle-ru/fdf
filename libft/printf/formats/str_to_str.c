/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:43:52 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:04:02 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_to_str(va_list *args, t_info *info)
{
	char	*s;

	info->flags &= (BLANK ^ CHAR_MAX);
	info->flags &= (PLUS ^ CHAR_MAX);
	(void)info;
	if (!(s = va_arg(*args, char*)))
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}
