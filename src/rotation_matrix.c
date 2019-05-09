/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:52:29 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/09 02:03:02 by rle-ru           ###   ########.fr       */
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
	m.m[2][1] = -s;
	m.m[1][2] = s;
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
	m.m[2][0] = s;
	m.m[1][1] = 1;
	m.m[0][2] = -s;
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
	m.m[1][0] = -s;
	m.m[1][1] = c;
	m.m[0][1] = s;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}

void			rotator(t_fdf *fdf, t_vector3 a)
{
	t_matrix	x;
	t_matrix	y;
	t_matrix	z;

	if (a.x)
		x = rotato_x(a.x);
	else
		ft_memcpy(&x, &fdf->unit, sizeof(t_matrix));
	if (a.y)
		y = rotato_y(a.y);
	else
		ft_memcpy(&y, &fdf->unit, sizeof(t_matrix));
	if (a.z)
		z = rotato_z(a.z);
	else
		ft_memcpy(&z, &fdf->unit, sizeof(t_matrix));
	x = mat_4_mul(3, x, y, z);
	ft_memcpy(&fdf->cam.rotation, &x, sizeof(t_matrix));
}
