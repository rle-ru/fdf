/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:58:16 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/10 13:52:05 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

int		key_hook(int key, t_fdf *fdf)
{
	double	speed;

	speed = 0.03;
	if (key == K_W || key == K_S)
		fdf->cam.pos.z += (key == K_W ? 1 : -1) * speed * 5;
	else if (key == K_A || key == K_D)
		fdf->cam.pos.y += (key == K_D ? 1 : -1) * speed * 5;
	else if (key == K_UP || key == K_DOWN)
		fdf->cam.rot_angles.x += (key == K_UP ? 1 : -1) * speed * 0.5;
	else if (key == K_LEFT || key == K_RIGHT)
		fdf->cam.rot_angles.z += (key == K_RIGHT ? 1 : -1) * speed * 0.5;
	else if (key == K_SPACE)
	{
		fdf->cam.rot_angles.x = 0;
		fdf->cam.rot_angles.z = 0;
		fdf->cam.pos.z = -20;
		fdf->cam.pos.y = 0;
	}
	else if (key == K_ESC)
		ft_leave(ok, fdf);
	ft_printf("Key is %d\n", key);
	rotator(fdf, fdf->cam.rot_angles);
	return (0);
}
