/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:00:32 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:41:49 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*cpy1;
	char	*cpy2;

	cpy1 = (char*)s1;
	cpy2 = (char*)s2;
	while (n--)
	{
		if (*cpy1 != *cpy2)
			return (*cpy1 - *cpy2);
		else
		{
			cpy1++;
			cpy2++;
		}
	}
	return (0);
}
