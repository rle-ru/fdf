/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:05:52 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/09 17:22:21 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdarg.h>

t_matrix	mat_4_mul(int nb, ...)
{
	va_list		args;
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	m;
	t_point		p;

	va_start(args, nb);
	m1 = va_arg(args, t_matrix);
	while (--nb)
	{
		m2 = va_arg(args, t_matrix);
		p.y = -1;
		while (++p.y < 4 && (p.x = -1))
			while (++p.x < 4)
			{
				m.m[p.y][p.x] = m1.m[p.y][0] * m2.m[0][p.x]
					+ m1.m[p.y][1] * m2.m[1][p.x]
					+ m1.m[p.y][2] * m2.m[2][p.x]
					+ m1.m[p.y][3] * m2.m[3][p.x];
			}
		m1 = m;
	}
	va_end(args);
	return (m);
}
