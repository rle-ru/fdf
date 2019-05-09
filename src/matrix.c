/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:37:04 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/09 17:20:35 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void		unit_matrix(t_fdf *fdf)
{
	fdf->unit.m[0][0] = 1;
	fdf->unit.m[1][1] = 1;
	fdf->unit.m[2][2] = 1;
	fdf->unit.m[3][3] = 1;
}

static void		projection_matrix(t_fdf *fdf)
{
	double	a;
	double	b;

	a = tan(FOV / 2.0);
	b = FAR - NEAR;
	fdf->cam.projection.m[0][0] = 1.0 / ((W_WIDTH / W_HEIGHT) * a);
	fdf->cam.projection.m[1][1] = 1.0 / a;
	fdf->cam.projection.m[2][2] = -((FAR + NEAR) / b);
	fdf->cam.projection.m[2][3] = -((2.0 * FAR * NEAR) / b);
	fdf->cam.projection.m[3][3] = -1.0; // sense etre [3][2]
}

void			init_matrixes(t_fdf *fdf)
{
	unit_matrix(fdf);
	projection_matrix(fdf);
}
