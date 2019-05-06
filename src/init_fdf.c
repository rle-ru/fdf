/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:09:08 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/06 18:19:21 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"

void	ft_init_fdf(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx_ptr, 500, 500, "fdf");
}
