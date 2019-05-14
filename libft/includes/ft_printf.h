/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 08:32:07 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/14 13:35:37 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# define JUSTIFY 1
# define ZERO 2
# define PLUS 4
# define BLANK 8
# define TAG 16
# define TAGL 32
# define TAGU 64
# define ISNEG 128

typedef struct	s_info
{
	char	flags;
	int		width;
	int		precision;
	char	specifier;
	char	*result;
	int		size;
	char	sub_specifier;
}				t_info;

typedef struct	s_translater
{
	char	type;
	char	*(*f)(va_list *param, t_info *info);
}				t_translater;

char			*ft_strjoin_free(char *left, char *right, char to_free);
char			*ft_strnjoin(char *s1, char *s2, size_t n);

int				ft_printf(const char *format, ...);
int				ft_fdprintf(int fd, const char *format, ...);
int				next_identifier(char *str);
t_info			*parser(char *string, va_list *args);
char			*record_string(char *format, va_list *args, t_translater *t);
t_translater	*create_table(void);

char			*str_to_str(va_list *args, t_info *info);
char			*int_to_str(va_list *args, t_info *info);
char			*char_to_str(va_list *args, t_info *info);
char			*longdouble_to_str(va_list *args, t_info *info);
char			*float_to_str(va_list *args, t_info *info);
char			*mod_to_str(va_list *param, t_info *info);
char			*uint_to_str(va_list *args, t_info *info);
char			*x_to_str(va_list *args, t_info *info);
char			*xu_to_str(va_list *args, t_info *info);
char			*o_to_str(va_list *args, t_info *info);
char			*b_to_str(va_list *args, t_info *info);
char			*p_to_str(va_list *args, t_info *info);

char			*distribute_floats(va_list *args, t_info *info);

void			get_flags(char **cursor, t_info *info);
void			get_width(char **cursor, t_info *info, va_list *args);
void			get_precision(char **cursor, t_info *info, va_list *args);
void			get_specifier(char **cursor, t_info *info);
void			get_sub_specifier(char **cursor, t_info *info);

void			set_zero_width(t_info *info);
void			set_width(t_info *info);
void			set_to_precision(t_info *info);
void			set_flags(t_info *info);

char			*ft_ltoabc(long n, int base, char cas);

#endif
