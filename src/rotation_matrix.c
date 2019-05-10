/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:52:29 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/10 13:52:35 by rle-ru           ###   ########.fr       */
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

void			rotator(t_fdf *fdf, t_vector3 a)
{
	t_matrix	x;
	t_matrix	y;
	t_matrix	z;

	x = a.x ? rotato_x(a.x) : fdf->unit;
	y = a.y ? rotato_y(a.y) : fdf->unit;
	z = a.z ? rotato_z(a.z) : fdf->unit;
	fdf->cam.rotation = mat_4_mul(3, x, y, z);
	t_point	p;
	p.y = -1;
}
