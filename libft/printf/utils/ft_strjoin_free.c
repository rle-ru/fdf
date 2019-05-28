/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:50:12 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:04:25 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_free(char *left, char *right, char to_free)
{
	char	*s;
	char	*new;
	char	*left_temp;
	char	*right_temp;

	left_temp = left;
	right_temp = right;
	s = ft_strnew(ft_strlen(left) + ft_strlen(right));
	new = s;
	while (*left)
		*s++ = *left++;
	while (*right)
		*s++ = *right++;
	if (to_free & LEFT)
		ft_strdel(&left_temp);
	if (to_free & RIGHT)
		ft_strdel(&right_temp);
	return (new);
}
