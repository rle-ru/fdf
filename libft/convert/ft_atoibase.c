/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:28:08 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/17 16:28:30 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_atoi_boucle(const char *str, size_t i, int base)
{
	int		res;
	int		j;
	char	*listebases;

	res = 0;
	j = 0;
	listebases = "0123456789ABCDEF";
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
	{
		res = res * base;
		if (str[i] >= '0' && str[i] <= '9')
			res = res + str[i] - 48;
		else
		{
			while (listebases[j] != str[i])
				j++;
			res = res + j;
			j = 0;
		}
		i++;
	}
	return (res);
}

int				ft_atoi_base(const char *str, int base)
{
	size_t	i;
	int		res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		str[i] == '-' ? neg = -1 : neg;
		i++;
	}
	res = ft_atoi_boucle(str, i, base);
	return (res * neg);
}
