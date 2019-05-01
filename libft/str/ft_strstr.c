/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:21:15 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:52:56 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	if (!(i = ft_strlen(s2)))
		return ((char*)s1);
	while (*s1)
		if (!ft_memcmp(s1++, s2, i))
			return ((char*)s1 - 1);
	return (0);
}
