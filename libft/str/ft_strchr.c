/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:17:23 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:04:46 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char*)s;
	if (c == '\0')
		return (&ret[ft_strlen(ret)]);
	while (*ret != c && *ret)
		ret++;
	if (*ret == '\0')
		return (0);
	else
		return (ret);
}
