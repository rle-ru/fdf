/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:07:09 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/16 01:45:41 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"
#include <math.h>

void		swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int			ipart(double x)
{
	return ((int)x);
}

// int			round(double x)
// {
// 	return (ipart(x + 0.5));
// }

double		fpart(double x)
{
	return (x > 0 ? x - ipart(x) : x - (ipart(x) + 1));
}

double		rfpart(double x)
{
	return (1 - fpart(x));
}

void		put_pixel(t_fdf *fdf, int x, int y, double op, int color)
{
	(void)op;
	if (x < fdf->canvas.w_width && x >= 0 && y < fdf->canvas.w_height && y >= 0)
		fdf->canvas.img.img[(int)(y * fdf->canvas.w_width + x)] = color;
		// fdf->canvas.img.img[(int)(y * fdf->canvas.w_width + x)] = color | ((ipart(op * 255) << 24));
}

void		xiaolin(t_fdf *fdf, t_point o, t_point t, t_point color)
{
	int		steep;
	double	dx;
	double	dy;
	double	gradient;
	int		xpx11;
	int		xpx12;
	double	inter;
	int		x;
	double	rel;
	double	pos;

	rel = (ft_abs(t.x - o.x) + ft_abs(t.y - o.y));
	pos = 0;

	(void)color;
	steep = ft_abs(t.y - o.y) > ft_abs(t.y - o.x);
	if (steep)
	{
		swap(&o.x, &o.y);
		swap(&t.x, &t.y);
	}
	if (o.x > t.x)
	{
		swap(&o.x, &t.x);
		swap(&o.y, &t.y);
	}
	dx = t.x - o.x;
	dy = t.y - o.y;
	gradient = dy / dx;
	if (!dx)
		gradient = 1;
	xpx11 = o.x;
	xpx12 = t.x;
	inter = o.y;
	if (steep)
	{
		x = xpx11;
		while (x < xpx12)
		{
			put_pixel(fdf, ipart(inter), x, rfpart(inter), get_color(color.x, color.y, pos / rel));
			put_pixel(fdf, ipart(inter) - 1, x, fpart(inter), get_color(color.x, color.y, pos / rel));
			inter += gradient;
			++x;
			++pos;
		}
	}
	else
	{
		x = xpx11;
		while (x < xpx12)
		{
			put_pixel(fdf, x, ipart(inter), rfpart(inter), get_color(color.x, color.y, pos / rel));
			put_pixel(fdf, x, ipart(inter) - 1, fpart(inter), get_color(color.x, color.y, pos / rel));
			inter += gradient;
			++x;
			++pos;
		}
	}
	
}

void		bresenham(t_fdf *fdf, t_point o, t_point t, t_point color)
{
	t_point	d;
	t_point	s;
	t_point	e;
	double	rel;
	double	pos;

	rel = (ft_abs(t.x - o.x) + ft_abs(t.y - o.y));
	pos = 0;
	d.x = ft_abs(t.x - o.x);
	s.x = o.x < t.x ? 1 : -1;
	d.y = ft_abs(t.y - o.y);
	s.y = o.y < t.y ? 1 : -1;
	e.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (o.x != t.x || o.y != t.y)
	{
		if (o.x >= 0 && o.x < fdf->canvas.w_width && o.y >= 0 && o.y < fdf->canvas.w_height)
			fdf->canvas.img.img[((o.y * (int)fdf->canvas.w_width) + o.x)] = get_color(color.x, color.y, pos / rel);
		else
			break ;
		e.y = e.x;
		if (e.y > -d.x)
		{
			e.x -= d.y;
			o.x += s.x;
		}
		if (e.y < d.y)
		{
			e.x += d.x;
			o.y += s.y;
		}
		++pos;
	}
}

void		put_line(t_fdf *fdf, int ox, int oy)
{
	t_point	c;
	t_point	o;
	t_point	color;
	int		temp;

	c.x = (int)fdf->project[oy * fdf->width + ox].x;
	c.y = (int)fdf->project[oy * fdf->width + ox].y;
	color.x = fdf->map[oy * fdf->width + ox].color;
	if (!isnan(c.x) && ox >= 0 && ox < fdf->width - 1)
	{
		color.y = fdf->map[oy * fdf->width + ox + 1].color;
		o.x = (int)fdf->project[oy * fdf->width + ox + 1].x;
		o.y = (int)fdf->project[oy * fdf->width + ox + 1].y;
		if (!isnan(o.x))
		{
			if (c.x >= 0 && c.x < fdf->canvas.w_width && c.y >= 0 && c.y < fdf->canvas.w_height)
				// bresenham(fdf, c, o, color);
				xiaolin(fdf, c, o, color);
			else if (o.x >= 0 && o.x < fdf->canvas.w_width && o.y >= 0 && o.y < fdf->canvas.w_height)
			{
				temp = color.y;
				color.y = color.x;
				color.x = temp;
				// bresenham(fdf, o, c, color);
				xiaolin(fdf, o, c, color);
			}
		}
	}
	if (!isnan(c.y) && oy >= 0 && oy < fdf->height - 1)
	{
		color.y = fdf->map[(oy + 1) * fdf->width + ox].color;
		o.x = (int)fdf->project[(oy + 1) * fdf->width + ox].x;
		o.y = (int)fdf->project[(oy + 1) * fdf->width + ox].y;
		if (!isnan(o.x))
		{
			if (c.x >= 0 && c.x < fdf->canvas.w_width && c.y >= 0 && c.y < fdf->canvas.w_height)
				// bresenham(fdf, c, o, color);
				xiaolin(fdf, c, o, color);
			else if (o.x >= 0 && o.x < fdf->canvas.w_width && o.y >= 0 && o.y < fdf->canvas.w_height)
			{
				temp = color.y;
				color.y = color.x;
				color.x = temp;
				// bresenham(fdf, o, c, color);
				xiaolin(fdf, o, c, color);
			}
		}
	}
}
