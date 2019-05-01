/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:27:54 by rle-ru            #+#    #+#             */
/*   Updated: 2018/11/27 15:27:59 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*mod_to_str(va_list *param, t_info *info)
{
	char	*s;

	(void)info;
	(void)param;
	s = ft_strnew(1);
	s[0] = '%';
	return (s);
}
