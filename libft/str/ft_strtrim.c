/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:30:27 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/01 06:53:07 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	size_t	len;

	if (!s)
		return (0);
	new = (char*)s;
	while (ft_isspace(*new))
		new++;
	len = ft_strlen(new);
	if (len)
	{
		while (ft_isspace(new[--len]) || *new == '\0')
			;
		new = ft_strsub(new, 0, (len + 1));
	}
	else
		new = ft_strnew(0);
	return (new);
}
