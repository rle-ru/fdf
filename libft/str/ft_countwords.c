/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:58:36 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/07 10:01:30 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_countwords(char *s, char c)
{
	size_t res;
	size_t i;

	i = 0;
	res = 0;
	while (s[i] && s[i] == c)
		++i;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			++i;
		++res;
		while (s[i] && s[i] == c)
			++i;
	}
	return (res);
}
