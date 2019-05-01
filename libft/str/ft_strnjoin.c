/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:08:13 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:51:57 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	char	*s;
	char	*ret;
	char	*temp;

	temp = s1;
	s = ft_strnew(ft_strlen(s1) + n + 1);
	ret = s;
	while (*s1)
		*s++ = *s1++;
	while (*s2 && n--)
		*s++ = *s2++;
	ft_strdel(&temp);
	return (ret);
}
