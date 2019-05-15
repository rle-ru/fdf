/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:37:04 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/15 22:26:04 by rle-ru           ###   ########.fr       */
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

static void		perspective_matrix(t_fdf *fdf)
{
	double	a;
	double	b;

	a = tan(FOV / 2.0);
	b = FAR - NEAR;
	fdf->cam.projection[0].m[0][0] = 1 / ((fdf->canvas.w_width / fdf->canvas.w_height) * a);
	fdf->cam.projection[0].m[1][1] = 1 / a;
	fdf->cam.projection[0].m[2][2] = -((FAR + NEAR) / b);
	fdf->cam.projection[0].m[2][3] = -((2.0 * FAR * NEAR) / b);
	fdf->cam.projection[0].m[3][2] = -1.0;
}

static void		isometric_matrix(t_fdf *fdf)
{
	fdf->cam.projection[1].m[0][0] = 0.707;
	fdf->cam.projection[1].m[0][1] = -0.707;
	fdf->cam.projection[1].m[1][0] = 0.409;
	fdf->cam.projection[1].m[1][1] = 0.409;
	fdf->cam.projection[1].m[1][3] = -0.816;
	fdf->cam.projection[1].m[2][0] = 0.577;
	fdf->cam.projection[1].m[2][1] = 0.577;
	fdf->cam.projection[1].m[2][3] = 0.578;
	fdf->cam.projection[1].m[3][3] = 1;
}

void			init_matrixes(t_fdf *fdf)
{
	unit_matrix(fdf);
	perspective_matrix(fdf);
	isometric_matrix(fdf);
	rotator(fdf, (t_vector3){0, 0, -M_PI, 0});
	fdf->cam.projection[1] = mat_4_mul(2, fdf->cam.projection[1],
		fdf->cam.rotation);
	rotator(fdf, fdf->cam.rot_angles);
}
