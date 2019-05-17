/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacuvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:58:16 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/17 17:46:17 by dacuvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"
#include "keys.h"

static void	reset_cam(t_fdf *fdf)
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

static void	ft_zoom(t_fdf *fdf, int key)
{
	if (key == K_Q && fdf->cam.pos.z > (fdf->width > fdf->height ? fdf->width : fdf->height) * -1)
		fdf->cam.pos.z -= 1 * fdf->speed * 5;
	else if (key == K_E && fdf->cam.pos.z < -10)
		fdf->cam.pos.z += 1 * fdf->speed * 5;
}

static void	ft_scaling(t_fdf *fdf, int key)
{
	if (key == K_MINUS && fdf->relief > -1.0)
		fdf->relief -= 0.1;
	if (key == K_PLUS && fdf->relief < 1.0)
		fdf->relief += 0.1;	
}

#include "libft.h"
int			key_hook(int key, t_fdf *fdf)
{
	if (key == K_Q || key == K_E)
		ft_zoom(fdf, key);
	else if (key == K_A || key == K_D)
		fdf->cam.pos.x += (key == K_A ? -1 : 1) * fdf->speed * 5;
	else if (key == K_W || key == K_S)
		fdf->cam.pos.y += (key == K_W ? -1 : 1) * fdf->speed * 5;
	else if (key == K_UP || key == K_DOWN)
	{
		fdf->cam.rot_angles.x += (key == K_UP ? 1 : -1) * fdf->speed * 0.1;
		rotator(fdf, fdf->cam.rot_angles);
	}
	else if (key == K_LEFT || key == K_RIGHT)
	{
		fdf->cam.rot_angles.z += (key == K_LEFT ? 1 : -1) * fdf->speed * 0.1;
		rotator(fdf, fdf->cam.rot_angles);
	}
	else if (key == K_SPACE)
		reset_cam(fdf);
	else if (key == K_ESC)
		ft_leave(ok, fdf);
	else if (key == K_PLUS || key == K_MINUS)
		ft_scaling(fdf, key);
	else if (key == K_PIPE && ++fdf->drawer)
	{
		if (fdf->drawer >= MAX_DRAW)
			fdf->drawer = 0;
	}
	else if (key == K_ENTER && ++fdf->proj)
		if (fdf->proj >= MAX_PROJ)
			fdf->proj = 0;
	// ft_printf("Key : %d\n", key);
	return (0);
}
