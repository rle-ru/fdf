/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:58:16 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/02 12:12:33 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"
#include "keys.h"

static void	ft_zoom(t_fdf *fdf, int key)
{
	if (key == K_Q && fdf->cam.pos.z >
		(fdf->width > fdf->height ? fdf->width : fdf->height) * -1)
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

static void	crea(t_fdf *fdf, int key)
{
	int	*x;
	int	*y;

	x = &(fdf->crea.current.x);
	y = &(fdf->crea.current.y);
	if (fdf->crea.mode == false)
		return ;
	if (key == K_I)
		*y += (*y > 0) ? -1 : 0;
	else if (key == K_K)
		*y += (*y < fdf->height - 1) ? 1 : 0;
	else if (key == K_J)
		*x += (*x > 0) ? -1 : 0;
	else if (key == K_L)
		*x += (*x < fdf->width - 1) ? 1 : 0;
	else if (key == K_T)
		fdf->map[*y * fdf->width + *x].z -= 10;
	else if (key == K_G)
		fdf->map[*y * fdf->width + *x].z += 10;
	select_color(fdf, *y * fdf->width + *x);
}

static int	key_hook2(int key, t_fdf *fdf)
{
	if (key == K_SPACE)
		reset_cam(fdf);
	else if (key == K_ESC)
		ft_leave(ok, fdf);
	else if (key == K_PLUS || key == K_MINUS)
		ft_scaling(fdf, key);
	else if (key == K_PIPE && ++fdf->drawer)
		fdf->drawer = fdf->drawer >= MAX_DRAW ? 0 : fdf->drawer;
	else if (key == K_C)
		fdf->crea.mode ^= 1;
	else if (key == K_I || key == K_J || key == K_K
			|| key == K_L || key == K_T || key == K_G)
		crea(fdf, key);
	else if (key == K_ENTER && ++fdf->proj)
		fdf->proj = fdf->proj >= MAX_PROJ ? 0 : fdf->proj;
	return (0);
}

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
		fdf->cam.rot_angles.x += (key == K_UP ? -1 : 1)
			* fdf->speed * 0.1 * (fdf->width > 200 ? 0.1 : 1);
		rotator(fdf, fdf->cam.rot_angles);
	}
	else if (key == K_LEFT || key == K_RIGHT)
	{
		fdf->cam.rot_angles.z += (key == K_LEFT ? 1 : -1)
			* fdf->speed * 0.1 * (fdf->width > 200 ? 0.1 : 1);
		rotator(fdf, fdf->cam.rot_angles);
	}
	return (key_hook2(key, fdf));
}
