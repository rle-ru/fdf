/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:52:29 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/08 23:23:07 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include "libft.h"

static void		rotato_x(t_fdf *fdf, double theta)
{
	double		c;
	double		s;

	ft_bzero(&fdf->cam.rot_x, sizeof(t_matrix));
	c = cos(theta);
	s = sin(theta);
	fdf->cam.rot_x[0][0] = 1;
	fdf->cam.rot_x[1][1] = c;
	fdf->cam.rot_x[2][1] = -s;
	fdf->cam.rot_x[1][2] = s;
	fdf->cam.rot_x[2][2] = c;
	fdf->cam.rot_x[3][3] = 1;
}

static void		rotato_y(t_fdf *fdf, double theta)
{
	double		c;
	double		s;

	ft_bzero(&fdf->cam.rot_y, sizeof(t_matrix));
	c = cos(theta);
	s = sin(theta);
	fdf->cam.rot_y[0][0] = c;
	fdf->cam.rot_y[2][0] = s;
	fdf->cam.rot_y[1][1] = 1;
	fdf->cam.rot_y[0][2] = -s;
	fdf->cam.rot_y[2][2] = c;
	fdf->cam.rot_y[3][3] = 1;
}

static void		rotato_z(t_fdf *fdf, double theta)
{
	double		c;
	double		s;

	c = cos(theta);
	s = sin(theta);
	ft_bzero(&fdf->cam.rot_z, sizeof(t_matrix));
	fdf->cam.rot_z[0][0] = c;
	fdf->cam.rot_z[1][0] = -s;
	fdf->cam.rot_z[1][1] = c;
	fdf->cam.rot_z[0][1] = s;
	fdf->cam.rot_z[2][2] = 1;
	fdf->cam.rot_z[3][3] = 1;
}

void			rotator(t_fdf *fdf, t_vector3 a)
{
	t_matrix	x;
	t_matrix	y;
	t_matrix	z;

	if (a.x)
	{
		rotato_x(fdf, a.x);
		ft_memcpy(&x, &fdf->cam.rot_x, sizeof(t_matrix));
	}
	else
		ft_memcpy(&x, &fdf->unit, sizeof(t_matrix));
	if (a.y)
	{
		rotato_y(fdf, a.y);
		ft_memcpy(&y, &fdf->cam.rot_y, sizeof(t_matrix));
	}
	else
		ft_memcpy(&y, &fdf->unit, sizeof(t_matrix));
	if (a.z)
	{
		rotato_z(fdf, a.z);
		ft_memcpy(&z, &fdf->cam.rot_z, sizeof(t_matrix));
	}
	else
		ft_memcpy(&z, &fdf->unit, sizeof(t_matrix));
	mat_4_mul(&x, y);
	mat_4_mul(&x, z);
	ft_memcpy(&fdf->cam.rotation, &x, sizeof(t_matrix));
}
