SRCSLIB=libft/ft_atoi.c libft/ft_strdup.c libft/ft_bzero.c libft/ft_putendl_fd.c libft/ft_isalnum.c\
		libft/ft_strnstr.c libft/ft_isalpha.c libft/ft_putnbr_fd.c libft/ft_striteri.c libft/ft_split.c\
		libft/ft_isascii.c libft/ft_memchr.c libft/ft_strjoin.c libft/ft_isdigit.c libft/ft_memcmp.c\
		libft/ft_putstr_fd.c libft/ft_strlcat.c libft/ft_substr.c libft/ft_isprint.c libft/ft_memcpy.c\
		libft/ft_strlen.c libft/ft_strtrim.c libft/ft_itoa.c libft/ft_strchr.c libft/ft_tolower.c\
		libft/ft_memmove.c libft/ft_strmapi.c libft/ft_toupper.c libft/ft_memset.c libft/ft_strncmp.c\
		libft/ft_putchar_fd.c libft/ft_strrchr.c libft/ft_strlcpy.c libft/ft_calloc.c libft/ft_lstnew.c\
		libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c\
		libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c libft/get_next_line.c\
		libft/ft_put_addr_fd.c libft/ft_put_base_fd.c libft/ft_printf.c libft/ft_atof.c

SRCS=main.c color.c parsing.c complex.c hooks.c mlx.c sets.c
OBJSLIB=${SRCSLIB:.c=.o}
FLAGS=-Wall -Werror -Wextra -g3
FRACTOL=fractol
LIBFT=libft.a
CC=cc
MLX=-I . -Lminilibx-linux -lmlx -lXext -lX11
ML=minilibx-linux/libmlx.a

all : ${FRACTOL}

%.o: %.c
	${CC} ${FLAGS} -I/usr/include -O3 -c $< -o $@

${FRACTOL} : ${LIBFT} ${SRCS} ${ML}
	${CC} ${FLAGS} -o ${FRACTOL} ${SRCS} ${LIBFT} ${MLX} -lm

${ML} :
	${MAKE} -C minilibx-linux

${LIBFT} : ${OBJSLIB}
	ar rc ${LIBFT} ${OBJSLIB}

cleanlib :
	rm -f ${OBJSLIB}

clean : cleanlib

fclean : clean
	rm -f ${FRACTOL} ${LIBFT}
	${MAKE} -C minilibx-linux clean

re : fclean all

.PHONY : all clean fclean re
