# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 10:58:33 by bwaterlo          #+#    #+#              #
#    Updated: 2018/12/06 11:22:28 by rle-ru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		ft_printf.c 			\
			next_identifier.c		\
			formats/str_to_str.c	\
			formats/int_to_str.c	\
			formats/char_to_str.c	\
			formats/float_to_str.c	\
			formats/longdouble_to_str.c	\
			formats/mod_to_str.c	\
			formats/uint_to_str.c	\
			formats/base_to_str.c	\
			utils/parser.c			\
			utils/get_infos.c		\
			utils/set_infos.c		\
			utils/ft_strjoin_free.c	\
			utils/composer.c		\
			formats/distribute_floats.c	\
									\
			ft_ltoabc.c				\
									\
			libft/char/ft_isalpha.c	\
			libft/char/ft_isdigit.c	\
			libft/char/ft_isalnum.c	\
			libft/char/ft_isascii.c	\
			libft/char/ft_isprint.c	\
			libft/char/ft_isupper.c	\
										\
			libft/convert/ft_atoi.c		\
			libft/convert/ft_toupper.c	\
			libft/convert/ft_tolower.c	\
			libft/convert/ft_itoa.c		\
			libft/convert/ft_ltoa.c		\
										\
			libft/lst/ft_lstnew.c		\
			libft/lst/ft_lstdelone.c	\
			libft/lst/ft_lstdel.c		\
			libft/lst/ft_lstadd.c		\
			libft/lst/ft_lstiter.c		\
			libft/lst/ft_lstmap.c		\
										\
			libft/maths/ft_pow.c		\
			libft/maths/ft_abs.c		\
										\
			libft/mem/ft_memset.c		\
			libft/mem/ft_bzero.c		\
			libft/mem/ft_memcpy.c		\
			libft/mem/ft_memccpy.c		\
			libft/mem/ft_memmove.c		\
			libft/mem/ft_memchr.c		\
			libft/mem/ft_memcmp.c		\
			libft/mem/ft_memalloc.c		\
			libft/mem/ft_memdel.c		\
										\
			libft/put/ft_putchar.c		\
			libft/put/ft_putstr.c		\
			libft/put/ft_putendl.c		\
			libft/put/ft_putnbr.c		\
			libft/put/ft_putchar_fd.c	\
			libft/put/ft_putstr_fd.c	\
			libft/put/ft_putendl_fd.c	\
			libft/put/ft_putnbr_fd.c	\
										\
			libft/str/ft_strlen.c		\
			libft/str/ft_strdup.c		\
			libft/str/ft_strcpy.c		\
			libft/str/ft_strncpy.c		\
			libft/str/ft_strcat.c		\
			libft/str/ft_strncat.c		\
			libft/str/ft_strlcat.c		\
			libft/str/ft_strchr.c		\
			libft/str/ft_strrchr.c		\
			libft/str/ft_strstr.c		\
			libft/str/ft_strnstr.c		\
			libft/str/ft_strcmp.c		\
			libft/str/ft_strncmp.c		\
			libft/str/ft_strnew.c		\
			libft/str/ft_strdel.c		\
			libft/str/ft_strclr.c		\
			libft/str/ft_striter.c		\
			libft/str/ft_striteri.c		\
			libft/str/ft_strmap.c		\
			libft/str/ft_strmapi.c		\
			libft/str/ft_strequ.c		\
			libft/str/ft_strnequ.c		\
			libft/str/ft_strsub.c		\
			libft/str/ft_strjoin.c		\
			libft/str/ft_strtrim.c		\
			libft/str/ft_strsplit.c		\
			libft/str/ft_strnjoin.c		\
			libft/str/ft_strndup.c		\
			libft/str/ft_strlenc.c		\

OBJS =		$(SRCS:%.c=%.o)

INCLUDES =	./includes

CFLAGS =	-Wall		\
			-Wextra		\
			-Werror		\
			-g			\
			-I ./includes

CC =		gcc

.PHONY :	all clean fclean re

$(NAME): $(OBJS)
	ar rc $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
