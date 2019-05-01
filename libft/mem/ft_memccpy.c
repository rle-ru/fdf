/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:40:56 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:41:07 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *cpyd;
	char *cpys;

	cpyd = (char*)dst;
	cpys = (char*)src;
	while (n > 0)
	{
		*cpyd = *cpys;
		if (*cpyd == (char)c)
			return (++cpyd);
		cpyd++;
		cpys++;
		n--;
	}
	return (0);
}
