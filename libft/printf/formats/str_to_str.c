/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:43:52 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/04 15:05:46 by bwaterlo         ###   ########.fr       */
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
