# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 10:58:33 by rle-ru            #+#    #+#              #
#    Updated: 2019/05/28 06:35:05 by rle-ru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				=	libft.a

# Dir Variables

SRCSDIR   			=	./

OBJSDIR   			=	obj

LIBSPATH			=	libs

LIBS				:=	

INC					=	-I includes

# File Variables

SRCS_RAW	:=	\
			convert/ft_atoibase.c		\
			printf/ft_printf.c 			\
			printf/next_identifier.c		\
			printf/formats/str_to_str.c	\
			printf/formats/int_to_str.c	\
			printf/formats/char_to_str.c	\
			printf/formats/float_to_str.c	\
			printf/formats/longdouble_to_str.c	\
			printf/formats/mod_to_str.c	\
			printf/formats/uint_to_str.c	\
			printf/formats/base_to_str.c	\
			printf/utils/parser.c			\
			printf/utils/ft_strjoin_free.c	\
			printf/utils/composer.c		\
			printf/formats/distribute_floats.c	\
			printf/utils/get_infos.c		\
			printf/utils/set_infos.c		\
									\
			printf/ft_ltoabc.c				\
									\
			char/ft_isalpha.c	\
			char/ft_isdigit.c	\
			char/ft_isalnum.c	\
			char/ft_isascii.c	\
			char/ft_isprint.c	\
			char/ft_isupper.c	\
										\
			convert/ft_atoi.c		\
			convert/ft_toupper.c	\
			convert/ft_tolower.c	\
			convert/ft_itoa.c		\
			convert/ft_ltoa.c		\
										\
			lst/ft_lstnew.c		\
			lst/ft_lstdelone.c	\
			lst/ft_lstdel.c		\
			lst/ft_lstadd.c		\
			lst/ft_lstiter.c		\
			lst/ft_lstmap.c		\
										\
			maths/ft_pow.c		\
			maths/ft_abs.c		\
										\
			mem/ft_memset.c		\
			mem/ft_bzero.c		\
			mem/ft_memcpy.c		\
			mem/ft_memccpy.c		\
			mem/ft_memmove.c		\
			mem/ft_memchr.c		\
			mem/ft_memcmp.c		\
			mem/ft_memalloc.c		\
			mem/ft_memdel.c		\
										\
			put/ft_putchar.c		\
			put/ft_putstr.c		\
			put/ft_putendl.c		\
			put/ft_putnbr.c		\
			put/ft_putchar_fd.c	\
			put/ft_putstr_fd.c	\
			put/ft_putendl_fd.c	\
			put/ft_putnbr_fd.c	\
										\
			str/ft_countwords.c	\
			str/ft_strlen.c		\
			str/ft_strdup.c		\
			str/ft_strcpy.c		\
			str/ft_strncpy.c		\
			str/ft_strcat.c		\
			str/ft_strncat.c		\
			str/ft_strlcat.c		\
			str/ft_strchr.c		\
			str/ft_strrchr.c		\
			str/ft_strstr.c		\
			str/ft_strnstr.c		\
			str/ft_strcmp.c		\
			str/ft_strncmp.c		\
			str/ft_strnew.c		\
			str/ft_strdel.c		\
			str/ft_strclr.c		\
			str/ft_striter.c		\
			str/ft_striteri.c		\
			str/ft_strmap.c		\
			str/ft_strmapi.c		\
			str/ft_strequ.c		\
			str/ft_strnequ.c		\
			str/ft_strsub.c		\
			str/ft_strjoin.c		\
			str/ft_strtrim.c		\
			str/ft_strsplit.c		\
			str/ft_strnjoin.c		\
			str/ft_strndup.c		\
			str/ft_strlenc.c		\
			get_next_line.c			\
									\

# 						END OF SRCS_RAW

SRCS				:=	$(SRCS_RAW:%.c=$(SRCSDIR)/%.c)

OBJS  				:=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

LIBOBJS				:=	$(patsubst %, %/obj/*.o, $(LIBS))

LIBFILES			:=	$(foreach LIB, $(LIBS), $(LIB)/$(notdir $(LIB)).a)

DEPENDENCIES		:=	$(OBJS:%.o=%.d)

# Compiler Config

CC					=	gcc

CFLAGS				+=	-Wall -Werror -Wextra -flto -O2

# Main Target

all					:	sublibs $(NAME)


$(NAME)				: 	$(OBJS) $(LIBFILES)
						ar rc $@ $(OBJS)
						ranlib $@

# Make SubLibs

.PHONY				:	sublibs
sublibs				:
						@$(foreach LIB, $(LIBS), make -C $(LIB);)

# Compile Objs

-include $(DEPENDENCIES)

$(OBJS)				: 	$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
						@mkdir -p $(OBJSDIR)
						@mkdir -p $(OBJSDIR)/printf
						@mkdir -p $(OBJSDIR)/printf/utils
						@mkdir -p $(OBJSDIR)/printf/formats
						@mkdir -p $(OBJSDIR)/char
						@mkdir -p $(OBJSDIR)/convert
						@mkdir -p $(OBJSDIR)/mem
						@mkdir -p $(OBJSDIR)/str
						@mkdir -p $(OBJSDIR)/lst
						@mkdir -p $(OBJSDIR)/maths
						@mkdir -p $(OBJSDIR)/put
						$(CC) -o $@ $(CFLAGS) $(INC) -MMD -c $<

# Cleanup

.PHONY				:	clean
clean				:
						rm -rf $(OBJSDIR)
						@$(foreach LIB, $(LIBS), make clean -C $(LIB);)

.PHONY				:	fclean
fclean				:	clean
						rm -f $(NAME)
						@$(foreach LIB, $(LIBS), make fclean -C $(LIB);)

.PHONY				:	re
re					:	fclean all
