/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:36:52 by dacuvill          #+#    #+#             */
/*   Updated: 2019/05/28 17:31:14 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

t_vector2	project_point(t_fdf *fdf, int x, int y)
{
	t_vector3	v;

	v = fdf->map[y * fdf->width + x];
	v.z *= fdf->relief;
	v = vec_3_sub(v, fdf->cam.rotpos);
	if (!fdf->proj)
		v = mat_4_mul_v(fdf->cam.rotation, v);
	if (v.z < 0.1)
		return ((t_vector2){NAN, NAN});
	v = mat_4_mul_v(fdf->cam.projection[fdf->proj], v);
	if (!v.z)
		v.z += 1e-6;
	return ((t_vector2){(v.x + 0.25) / v.z * fdf->canvas.w_width,
			(v.y + 0.25) / v.z * fdf->canvas.w_height});
}
