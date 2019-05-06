/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:38:14 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/06 18:39:11 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef enum	e_error
{
	ok,
	falloc,
	usage,
	filepath,
	badline
}				t_error;

typedef struct	s_line
{
	char		*line;
	int			nbx;
}				t_line;

typedef	struct	s_fdf
{
	void		*mlx_ptr;
	void		*window;
	int			fd;
	int			nblines;
	char		*fname;
	t_line		*lines;
	int			lines_capacity;
	int			*map;
}				t_fdf;

t_error			ft_open_file(int ac, char **av, t_fdf *fdf);
void			ft_init_fdf(t_fdf *fdf);
t_error			ft_parse_file(t_fdf *fdf);
t_error			ft_create_map(t_fdf *fdf);
int				ft_leave(t_error ret, t_fdf *fdf);
void			free_lines(t_fdf *fdf);

#endif
