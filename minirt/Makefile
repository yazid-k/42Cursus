LIBFT=libs/libft/libft.a
MLX=libs/minilibx-linux/libmlx.a
SRCS=$(addprefix srcs/, main.c\
	$(addprefix parsing/, parsing.c param_1.c param_2.c elem_1.c elem_2.c)\
	$(addprefix utils/, utils_1.c utils_2.c utils_3.c color.c)\
	$(addprefix mlx/, mlx.c)\
	$(addprefix elem/, lst.c init_1.c init_2.c init_3.c)\
	$(addprefix math/, math_1.c math_2.c hit.c normal.c)\
	$(addprefix render/, render.c colors.c))

OBJS=${SRCS:.c=.o}
CC=cc
FLAGS=-Wall -Werror -Wextra -c
NAME=minirt

all : ${NAME}

%.o: %.c
	${CC} ${FLAGS} $< -o $@

${NAME} : ${LIBFT} ${OBJS} ${MLX}
	${CC} -o ${NAME} ${OBJS} ${LIBFT} -lmlx -L./libs/minilibx-linux -lX11 -lm -lXext

${LIBFT} :
	make -C libs/libft

${MLX} :
	make -C libs/minilibx-linux

clean :
	make -C libs/libft $@
	make -C libs/minilibx-linux $@
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}
	make -C libs/libft $@

re : fclean all

.PHONY: all clean fclean re
