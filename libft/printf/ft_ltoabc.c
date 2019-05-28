/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoabc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:28:50 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:04:10 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lowup(char **tail, long uarg, int base, char cas)
{
	long	quot;
	long	rem;
	int		i;

	i = 1;
	while (uarg)
	{
		quot = uarg / base;
		rem = uarg % base;
		if (ft_isupper(cas))
			**tail = (char)(rem + ((9L < rem) ? ('A' - 10L) : '0'));
		else
			**tail = (char)(rem + ((9L < rem) ? ('a' - 10L) : '0'));
		*tail -= 1;
		uarg = quot;
		++i;
	}
	return (i);
}

int			ft_ltoabc_aux(long n, char **tail, int base, char cas)
{
	int		i;

	i = 2;
	if (n)
		i = lowup(tail, n, base, cas);
	else
	{
		**tail = '0';
		(*tail)--;
	}
	return (i);
}

char		*ft_ltoabc(long n, int base, char cas)
{
	char	*s;
	char	buf[sizeof( long) * 8 + 1];
	char	*tail;
	char	*head;
	int		i;

	if (base > 36 || base < 2)
		base = 10;
	if (!(s = ft_memalloc(sizeof( long) * 8 + 1)))
		return (0);
	i = 2;
	head = s;
	tail = &buf[sizeof( long) * 8];
	*tail-- = '\0';
	i = ft_ltoabc_aux(n, &tail, base, cas);
	ft_memcpy(head, ++tail, i);
	return (s);
}
