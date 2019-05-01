/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 08:48:43 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:47:34 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		l;
	char	*str;

	i = -1;
	l = ft_strlen(src);
	if (!(str = (char*)malloc(sizeof(*str) * (l + 1))))
		return (NULL);
	while (++i < l)
		str[i] = src[i];
	str[l] = '\0';
	return (str);
}
