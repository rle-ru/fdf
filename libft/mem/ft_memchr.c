/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:09:10 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:41:27 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*cpy;

	cpy = (char*)s;
	while (n--)
	{
		if (*cpy != (char)c)
			cpy++;
		else
			return (cpy);
	}
	return (0);
}
