/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:25:16 by dacuvill          #+#    #+#             */
/*   Updated: 2019/06/01 20:31:28 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			put_pixels(t_fdf *fdf)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fdf->height && (x = -1))
		while (++x < fdf->width)
		{
			// z-buffer
			fdf->current_depth = fdf->depths[y * fdf->width + x];
			// z-buffer
			put_line(fdf, x, y);
		}
	return (0);
}
