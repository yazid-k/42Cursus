LIBFT=libs/libft/libft.a
MLX=libs/MinilibX/libmlx.a
SRCS=$(addprefix srcs/, main.c $(addprefix parsing/, parsing.c param_1.c param_2.c elem_1.c elem_2.c) $(addprefix utils/, utils_1.c utils_2.c)\
		$(addprefix mlx/, mlx.c))
OBJS=${SRCS:.c=.o}
CC=cc
FLAGS=-Wall -Werror -Wextra -c
NAME=minirt

all : ${NAME}

%.o: %.c
	${CC} ${FLAGS} $< -o $@

${NAME} : ${LIBFT} ${OBJS} ${MLX}
	${CC} -o ${NAME} ${OBJS} ${LIBFT} -lmlx -L./libs/MinilibX -framework OpenGL -framework AppKit

${LIBFT} :
	make -C libs/libft

${MLX} :
	make -C libs/MinilibX

clean :
	make -C libs/libft $@
	make -C libs/MinilibX $@
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}
	make -C libs/MinilibX $@
	make -C libs/libft $@

re : fclean all

.PHONY: all clean fclean re
