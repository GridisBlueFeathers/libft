NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

SRCS = ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memset.c \
	   ft_strlen.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   

OBJS = ${SRCS:.c=.o}

INCLUDES = -I libft

LIBC = ar rcs

RM = rm -f

all: ${NAME}


${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} $< ${INCLUDES} -o $@ 

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
