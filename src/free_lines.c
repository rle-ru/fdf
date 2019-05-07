/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 17:50:33 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/07 13:06:51 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

void	free_lines(t_fdf *fdf)
{
	t_line	*cur;
	t_line	*tmp;

	cur = fdf->lines;
	while (cur != NULL)
	{
		tmp = cur;
		free(cur->line);
		cur = cur->next;
		free(tmp);
	}
	fdf->last_line = NULL;
	fdf->lines = NULL;
}
