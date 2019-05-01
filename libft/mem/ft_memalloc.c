/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:01:24 by rle-ru            #+#    #+#             */
/*   Updated: 2019/02/27 12:29:43 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*temp;

	if (size == 0)
		return (0);
	if (!(temp = (char*)malloc(size)))
		return (NULL);
	ft_memset(temp, '\0', size);
	return (temp);
}
