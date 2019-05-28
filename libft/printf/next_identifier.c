/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:24:44 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:04:20 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		next_identifier(char *str)
{
	long	index;

	index = ft_strchr(str, '%') - str;
	return (index >= 0 ? index : -1);
}
