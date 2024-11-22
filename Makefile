# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 14:07:03 by svereten          #+#    #+#              #
#    Updated: 2024/11/22 17:35:04 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src

OBJS_DIR = obj

SRCS_PROJ = libft/ft_memset \
			libft/ft_strlen \
			libft/ft_bzero \
			libft/ft_memcpy \
			libft/ft_memmove \
			libft/ft_memchr \
			libft/ft_memcmp \
			libft/ft_toupper \
			libft/ft_tolower \
			libft/ft_strchr \
			libft/ft_strrchr \
			libft/ft_strncmp \
			libft/ft_strcmp \
			libft/ft_strlcpy \
			libft/ft_strlcat \
			libft/ft_strnstr \
			libft/ft_strdup \
			libft/ft_substr \
			libft/ft_strjoin \
			libft/ft_strtrim \
			libft/ft_count_words \
			libft/ft_split \
			libft/ft_strmapi \
			libft/ft_striteri \
			libft/ft_putchar_fd \
			libft/ft_putstr_fd \
			libft/ft_putendl_fd \
			libft/ft_putnbr_fd \
			libft/ft_lstnew \
			libft/ft_lstadd_front \
			libft/ft_lstadd_back \
			libft/ft_lstsize \
			libft/ft_lstlast \
			libft/ft_lstdelone \
			libft/ft_lstclear \
			libft/ft_lstiter \
			libft/ft_lstmap \
			libft/ft_strarrdup \
			libft/ft_strarrlen \
			libft/ft_strarrcmp \
			libft/ft_putstrarr_fd \
			libft/ft_open \
			libft/ft_close \
			ctype/ft_isalpha \
			ctype/ft_isascii \
			ctype/ft_isdigit \
			ctype/ft_isprint \
			ctype/ft_isnumber \
			ctype/ft_isalnum \
			stdlib/ft_atoi \
			stdlib/ft_atoi_check \
			stdlib/ft_itoa \
			stdlib/ft_calloc \
			stdlib/ft_free \
			stdlib/ft_panic \
			stdlib/ft_exit \
			gnl/get_next_line \
			ft-printf/ft_print_uint \
			ft-printf/ft_print_uhex \
			ft-printf/ft_print_pointer_addr \
			ft-printf/ft_printf \
			internal/gc/gc \
			internal/gc/gc_data \
			internal/ft_calloc_no_gc \
			internal/libft_init \

OBJS = ${SRCS_PROJ:%=${OBJS_DIR}/%.o}

INCLUDES = -I./include -I./internal

AR = ar -rcs

RM = rm -rf

OBJS_DIRS = ${sort ${dir ${OBJS}}} obj/gnl

GNL_SIZE ?= -D BUFFER_SIZE=42

all: ${NAME}

${NAME}: ${OBJS} obj/gnl/get_next_line.o
	${AR} ${NAME} $^

obj/gnl/get_next_line.o: src/gnl/get_next_line.c | ${OBJS_DIRS}
	${CC} ${CFLAGS} ${GNL_SIZE} -c $< ${INCLUDES} -o $@


${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIRS}
	${CC} ${CFLAGS} -c $< ${INCLUDES} -o $@ 

${OBJS_DIRS}:
	mkdir -p $@

clean:
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
