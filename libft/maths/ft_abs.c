/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:19:36 by bwaterlo          #+#    #+#             */
/*   Updated: 2019/02/28 14:18:05 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_abs(long input)
{
	if (input == LONG_MIN)
		return ((long)LONG_MIN);
	return (input < 0) ? input * -1 : input;
}
