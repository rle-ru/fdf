/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:48:27 by rle-ru            #+#    #+#             */
/*   Updated: 2018/11/12 14:51:40 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	res;
	int		i;

	dst_len = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[dst_len])
		++dst_len;
	res = (dstsize <= dst_len) ? dstsize : dst_len;
	i = -1;
	while (src[++i])
		res++;
	i = 0;
	while (src[i] && i + dst_len < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (res);
}
