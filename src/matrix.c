/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:37:04 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/10 22:55:38 by rle-ru           ###   ########.fr       */
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
	fdf->cam.projection[0].m[0][0] = 1 / ((W_WIDTH / W_HEIGHT) * a);
	fdf->cam.projection[0].m[1][1] = 1 / a;
	fdf->cam.projection[0].m[2][2] = -((FAR + NEAR) / b);
	fdf->cam.projection[0].m[2][3] = -((2.0 * FAR * NEAR) / b);
	fdf->cam.projection[0].m[3][2] = -1.0;
}

#include "libft.h"//
static void		orthographic_matrix(t_fdf *fdf)
{
	t_matrix	m;
	double		alpha;
	double		beta;
	double		cosa;
	double		cosb;
	double		sina;
	double		sinb;

	alpha = 35.264;
	beta = 45;
	cosa = cos(alpha);
	cosb = cos(beta);
	sina = sin(alpha);
	sinb = sin(beta);
	ft_bzero(&m, sizeof(t_matrix));
	m.m[0][0] = cosa;
	m.m[0][1] = sina * sinb;
	m.m[1][1] = cosb;
	m.m[2][0] = sina;
	m.m[2][1] = -sinb * cosa;
	m.m[3][3] = 1;

	// m.m[0][0] = W_WIDTH / (W_RIGHT - W_LEFT);
	// m.m[0][3] = ((-W_LEFT * W_WIDTH) / (W_RIGHT - W_LEFT));
	// m.m[1][1] = W_HEIGHT / (W_BOTTOM - W_TOP);
	// m.m[1][3] = ((-W_TOP * W_HEIGHT) / (W_BOTTOM - W_TOP));
	// m.m[2][2] = ((500) / (FAR - NEAR));
	// m.m[2][3] = ((-NEAR * 500) / (FAR - NEAR));
	// m.m[3][3] = 1;

	// m.m[0][0] = 2 / (W_RIGHT - W_LEFT);
	// m.m[0][3] = -((W_RIGHT + W_LEFT) / (W_RIGHT - W_LEFT));
	// m.m[1][1] = 2 / (W_TOP - W_BOTTOM);
	// m.m[1][3] = -((W_TOP + W_BOTTOM) / (W_TOP - W_BOTTOM));
	// m.m[2][2] = -2 / (FAR - NEAR);
	// m.m[2][3] = -((FAR + NEAR) / (FAR - NEAR));
	// m.m[3][3] = 1;
	// m.m[0][0] = 2 / W_WIDTH;
	// m.m[1][1] = 2 / W_HEIGHT;
	// m.m[2][2] = 1 / (FAR - NEAR);
	// m.m[2][3] = -NEAR / (FAR - NEAR);
	// m.m[3][3] = 1;
	fdf->cam.projection[1] = m;
}

void			init_matrixes(t_fdf *fdf)
{
	unit_matrix(fdf);
	perspective_matrix(fdf);
	orthographic_matrix(fdf);
	rotator(fdf, fdf->cam.rot_angles);
}
