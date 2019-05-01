/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:57:37 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:53:01 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strsub(char const *s, int start, size_t len)
{
	char	*new;

	if (!s)
		return (0);
	if (!(new = ft_strnew(len)))
		return (0);
	ft_strncpy(new, &s[start], len);
	return (new);
}
