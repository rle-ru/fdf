/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:52:29 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/02 14:23:56 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include "libft.h"

static t_matrix		rotato_x(double theta)
{
	double		c;
	double		s;
	t_matrix	m;

	ft_bzero(&m, sizeof(t_matrix));
	c = cos(theta);
	s = sin(theta);
	m.m[0][0] = 1;
	m.m[1][1] = c;
	m.m[1][2] = -s;
	m.m[2][1] = s;
	m.m[2][2] = c;
	m.m[3][3] = 1;
	return (m);
}

static t_matrix		rotato_y(double theta)
{
	double		c;
	double		s;
	t_matrix	m;

	ft_bzero(&m, sizeof(t_matrix));
	c = cos(theta);
	s = sin(theta);
	m.m[0][0] = c;
	m.m[0][2] = s;
	m.m[1][1] = 1;
	m.m[2][0] = -s;
	m.m[2][2] = c;
	m.m[3][3] = 1;
	return (m);
}

static t_matrix		rotato_z(double theta)
{
	double		c;
	double		s;
	t_matrix	m;

	ft_bzero(&m, sizeof(t_matrix));
	c = cos(theta);
	s = sin(theta);
	m.m[0][0] = c;
	m.m[0][1] = -s;
	m.m[1][0] = s;
	m.m[1][1] = c;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}

void				rotator(t_fdf *fdf, t_vector3 a)
{
	t_bool		recalc;

	recalc = false;
	if (a.x != fdf->cam.pre_rot_angles.x)
	{
		fdf->rot_x = rotato_x(a.x);
		fdf->cam.pre_rot_angles.x = a.x;
		recalc = true;
	}
	if (a.y != fdf->cam.pre_rot_angles.y)
	{
		fdf->rot_y = rotato_y(a.y);
		fdf->cam.pre_rot_angles.y = a.y;
		recalc = true;
	}
	if (a.z != fdf->cam.pre_rot_angles.z)
	{
		fdf->rot_z = rotato_z(a.z);
		fdf->cam.pre_rot_angles.z = a.z;
		recalc = true;
	}
	if (recalc == true)
		fdf->cam.rotation = mat_4_mul(4, fdf->rot_x, fdf->rot_y, fdf->rot_z,
			fdf->cam.projection[fdf->proj]);
}
