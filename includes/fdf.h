#ifndef FDF_H
# define FDF_H

typedef enum	s_error
{
	ok,
	falloc,
	usage,
	filepath
}				t_error;

typedef	struct 	s_fdf
{
	void		*mlx_ptr;
	void		*window;
	int			fd;
	char		*fname;
}				t_fdf;


t_error			open_file(int ac, char **av, t_fdf *fdf);
void			init_fdf(t_fdf *fdf);
int				ft_leave(t_error ret, t_fdf *fdf);

#endif
