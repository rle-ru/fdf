/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:06:11 by rle-ru            #+#    #+#             */
/*   Updated: 2018/11/09 13:24:50 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst && alst)
	{
		if ((*alst)->next)
		{
			ft_lstdel(&(*alst)->next, del);
		}
		ft_lstdelone(alst, del);
	}
}
