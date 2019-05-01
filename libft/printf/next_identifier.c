/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:24:44 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/23 12:42:13 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		next_identifier(char *str)
{
	long	index;

	index = ft_strchr(str, '%') - str;
	return (index >= 0 ? index : -1);
}
