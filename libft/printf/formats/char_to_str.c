/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:03:46 by rle-ru            #+#    #+#             */
/*   Updated: 2019/02/28 14:22:59 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_to_str(va_list *args, t_info *info)
{
	char	*s;

	(void)info;
	s = ft_strnew(1);
	s[0] = va_arg(*args, int);
	return (s);
}
