LIBFT=libft/libft.a
SRCS=main.c Parsing/tokenization/token_func_1.c Parsing/tokenization/token_func_2.c Parsing/tokenization/token_func_3.c Parsing/tokenization/token_func_4.c \
	Parsing/tokenization/cmd_func_1.c Parsing/tokenization/cmd_func_2.c Parsing/tokenization/cmd_func_3.c Parsing/parsing_1.c Parsing/parsing_2.c Parsing/parsing_3.c\
	Parsing/string_modif.c Parsing/expand/expand_1.c Parsing/expand/init_env.c
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
