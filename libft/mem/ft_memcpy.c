/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:27:41 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:42:00 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cpyd;
	char	*cpys;

	cpyd = (char*)dst;
	cpys = (char*)src;
	while (n > 0)
	{
		*cpyd = *cpys;
		cpyd++;
		cpys++;
		n--;
	}
	return (dst);
}
