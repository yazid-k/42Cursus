LIBFT=libft/libft.a
SRCS=main.c \
		srcs/expand/expand_1.c srcs/expand/expand_2.c srcs/expand/expand_3.c srcs/expand/env.c\
		srcs/str/str_1.c srcs/str/str_2.c\
		srcs/token/token_1.c srcs/token/token_2.c srcs/token/token_3.c\
		srcs/cmd/cmd_1.c srcs/cmd/cmd_2.c srcs/cmd/cmd_3.c srcs/cmd/cmd_4.c\
		srcs/parsing/parsing_1.c srcs/parsing/parsing_2.c srcs/parsing/parsing_3.c\


CC=cc
FLAGS=-Wall -Werror -Wextra
NAME=minishell

%.o: %.c
	${CC} ${FLAGS} $< -o $@

${NAME} : ${LIBFT} ${SRCS}
	${CC} ${FLAGS} -lreadline  -o ${NAME} ${SRCS} ${LIBFT}

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
