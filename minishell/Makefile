LIBFT=libft/libft.a
SRCS=main.c Parsing/parsing.c Parsing/token_func_1.c Parsing/token_func_2.c Parsing/token_func_3.c Parsing/token_func_4.c \
		Parsing/cmd_func_1.c Parsing/cmd_func_2.c Parsing/cmd_func_3.c
CC=cc
FLAGS=-Wall -Werror -Wextra
NAME=minishell

%.o: %.c
	${CC} ${FLAGS} $< -o $@

${NAME} : ${LIBFT} ${SRCS}
	${CC} ${FLAGS} -o ${NAME} ${SRCS} ${LIBFT}

all : ${NAME}

${LIBFT} :
	make -C libft

cleanlib :
	make -C libft clean

clean : cleanlib

fclean :
	rm -f ${NAME}
	make -C libft fclean

re : fclean all
