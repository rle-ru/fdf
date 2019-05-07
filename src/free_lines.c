/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:50:33 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/07 12:10:35 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

void	free_lines(t_fdf *fdf)
{
	t_line	*cur;
	t_line	*tmp;

	cur = fdf->lines;
	while (cur != NULL)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}
