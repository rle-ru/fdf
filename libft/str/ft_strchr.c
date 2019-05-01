/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:17:23 by rle-ru            #+#    #+#             */
/*   Updated: 2019/01/09 18:28:17 by bwaterlo         ###   ########.fr       */
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
