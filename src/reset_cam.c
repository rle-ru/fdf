/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:46:46 by dacuvill          #+#    #+#             */
/*   Updated: 2019/05/24 13:13:06 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	reset_cam(t_fdf *fdf)
{
	fdf->cam.pos.z = (fdf->width > fdf->height ? fdf->width : fdf->height) * -1;
	fdf->cam.pos.x = fdf->width >> 3;
	fdf->cam.pos.y = fdf->height >> 3;
	fdf->cam.rot_angles.z = -M_PI;
	fdf->cam.rot_angles.x = 0;
	fdf->cam.rot_angles.y = 0;
	fdf->relief = 0.1;
	rotator(fdf, fdf->cam.rot_angles);
}
