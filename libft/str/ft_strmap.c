/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:30:59 by rle-ru            #+#    #+#             */
/*   Updated: 2018/11/08 18:43:16 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s)
		return (0);
	i = 0;
	if (!(new = ft_strnew(ft_strlen(s))))
		return (0);
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
