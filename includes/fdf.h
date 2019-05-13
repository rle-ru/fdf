/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:38:14 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/13 19:25:52 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX_PROJ 2
# define W_HEIGHT 500.0
# define W_WIDTH 500.0
# define FOV 110.0 * M_PI / 180.0
# define FAR 10.0
# define NEAR 0.1
# define W_LEFT -500.0
# define W_RIGHT 500.0
# define W_BOTTOM 500.0
# define W_TOP -500.0
# define C_GROUND 0xFF8000
# define C_DEEP 0x003366
# define C_SUMMIT 0xE0E0E0

typedef enum		e_bool
{
	false,
	true
}					t_bool;

typedef enum		e_error
{
	ok,
	falloc,
	usage,
	filepath,
	badline
}					t_error;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_line
{
	char			*line;
	int				nbx;
	struct s_line	*next;
}					t_line;

typedef struct		s_matrix
{
	double			m[4][4];
}					t_matrix;

typedef struct		s_vector2
{
	double			x;
	double			y;
}					t_vector2;

typedef struct		s_vector3
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_vector3;

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
}					t_map;

typedef struct		s_cam
{
	t_vector3		pos;
	t_matrix		projection[2];
	t_matrix		rotation;
	t_vector3		rot_angles;
}					t_cam;

typedef	struct		s_fdf
{
	void			*mlx_ptr;
	void			*window;
	void			*img;
	int				fd;
	char			*fname;
	int				nblines;
	t_line			*lines;
	t_line			*last_line;
	int				width;
	int				maxz;
	int				minz;
	t_vector3		*map;
	t_vector2		*project;
	t_cam			cam;
	t_matrix		unit;
	int				proj;
}					t_fdf;

t_error				ft_open_file(int ac, char **av, t_fdf *fdf);
void				ft_init_fdf(t_fdf *fdf);
t_error				ft_parse_file(t_fdf *fdf);
t_error				ft_create_map(t_fdf *fdf);
int					ft_leave(t_error ret, t_fdf *fdf);
void				free_lines(t_fdf *fdf);
void				init_matrixes(t_fdf *fdf);
int					key_hook(int key, t_fdf *fdf);
int					draw_map(t_fdf *fdf);
t_matrix			mat_4_mul(int nb, ...);
void				bresenham(t_fdf *fdf, t_point o, t_point t, t_point color);
void				put_line(t_fdf *fdf, int ox, int oy);
t_vector3			mat_4_mul_v(t_matrix m, t_vector3 v);
int					get_color(int from, int to, double a);

t_vector3			vec_3_add(t_vector3 a, t_vector3 b);
t_vector3			vec_3_sub(t_vector3 a, t_vector3 b);
void				rotator(t_fdf *fdf, t_vector3 a);
int					hook_leave(t_fdf *fdf);

#endif
