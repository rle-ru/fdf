/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:38:14 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/08 23:32:56 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W_HEIGHT 500.0
# define W_WIDTH 500.0
# define FOV 60.0 * M_PI / 180
# define FAR 100
# define NEAR 0.1
# define FORWARD 126
# define BACKWARD 125
# define K_LEFT 123
# define K_RIGHT 124
# define ROT_UP 13
# define ROT_DOWN 1
# define ROT_LEFT 0
# define ROT_RIGHT 2

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

typedef struct		s_line
{
	char			*line;
	int				nbx;
	struct s_line	*next;
}					t_line;

typedef double		t_matrix[4][4];

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
	t_matrix		projection;
	t_matrix		rotation;
	t_vector3		rot_angles;
	t_matrix		rot_x;
	t_matrix		rot_y;
	t_matrix		rot_z;
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
	t_vector3		*map;
	t_vector2		*project;
	t_cam			cam;
	t_matrix		unit;
}					t_fdf;

t_error				ft_open_file(int ac, char **av, t_fdf *fdf);
void				ft_init_fdf(t_fdf *fdf);
t_error				ft_parse_file(t_fdf *fdf);
t_error				ft_create_map(t_fdf *fdf);
void				ft_leave(t_error ret, t_fdf *fdf);
void				free_lines(t_fdf *fdf);
void				init_matrixes(t_fdf *fdf);
t_vector3			mat_4_mul_v(t_matrix m, t_vector3 v);
void				mat_4_mul(t_matrix *a, t_matrix b);
t_vector3			vec_3_add(t_vector3 a, t_vector3 b);
t_vector3			vec_3_sub(t_vector3 a, t_vector3 b);
void				rotator(t_fdf *fdf, t_vector3 a);

#endif
