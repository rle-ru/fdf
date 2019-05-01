/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:44:31 by rle-ru            #+#    #+#             */
/*   Updated: 2018/11/09 14:17:00 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst)
		return (0);
	new = f(ft_lstnew(lst->content, lst->content_size));
	if (!new)
		return (0);
	if (lst->next)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
