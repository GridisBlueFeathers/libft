NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

ALL_SRCS = ${wildcard *.c}

BONUS_SRCS = ${wildcard *_bonus.c}

SRCS = ${filter-out ${BONUS_SRCS}, ${ALL_SRCS}}

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

INCLUDES = -I libft

AR = ar rcs

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

bonus: ${BONUS_OBJS}

%.o: %.c
	${CC} ${CFLAGS} $< ${INCLUDES} -o $@ 

%_bonus.o: %_bonus.c
	${CC} ${CFLAGS} $< ${INCLUDES} -o $@ 
	${AR} ${NAME} $@

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
