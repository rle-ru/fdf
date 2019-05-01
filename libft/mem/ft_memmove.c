/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:01:24 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:42:50 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*cpydst;
	char	*cpysrc;

	cpydst = (char*)dst;
	cpysrc = (char*)src;
	i = dst < src ? 0 : (int)len - 1;
	if (dst > src)
		while (i >= 0)
		{
			cpydst[i] = cpysrc[i];
			i--;
		}
	else
		while (i <= (int)len - 1)
		{
			cpydst[i] = cpysrc[i];
			i++;
		}
	return (dst);
}
