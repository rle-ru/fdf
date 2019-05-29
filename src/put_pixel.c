/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:58:24 by dacuvill          #+#    #+#             */
/*   Updated: 2019/05/28 18:13:37 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x < fdf->canvas.w_width && x >= 0 && y < fdf->canvas.w_height && y >= 0)
		fdf->canvas.img.img[(int)(y * fdf->canvas.w_width + x)] = color;
}
