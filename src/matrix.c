/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:37:04 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/08 22:50:15 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void		unit_matrix(t_fdf *fdf)
{
	fdf->unit[0][0] = 1;
	fdf->unit[1][1] = 1;
	fdf->unit[2][2] = 1;
	fdf->unit[3][3] = 1;
}

static void		projection_matrix(t_fdf *fdf)
{
	double	a;
	double	b;

	a = tan(FOV / 2);
	b = FAR - NEAR;
	fdf->cam.projection[0][0] = 1 / ((W_WIDTH / W_HEIGHT)) * a;
	fdf->cam.projection[1][1] = 1 / a;
	fdf->cam.projection[2][2] = -((FAR + NEAR) / b);
	fdf->cam.projection[2][3] = -((2 * FAR * NEAR) / b);
	fdf->cam.projection[3][2] = -1;
}

void			init_matrixes(t_fdf *fdf)
{
	unit_matrix(fdf);
	projection_matrix(fdf);
}
