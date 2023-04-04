LIBFT=libft/libft.a
SRCS=main.c \
		srcs/expand/expand_1.c srcs/expand/expand_2.c srcs/expand/expand_3.c srcs/expand/env.c\
		srcs/str/str_1.c srcs/str/str_2.c\
		srcs/token/token_1.c srcs/token/token_2.c srcs/token/token_3.c\
		srcs/cmd/cmd_1.c srcs/cmd/cmd_2.c srcs/cmd/cmd_3.c srcs/cmd/cmd_4.c\
		srcs/parsing/parsing_1.c srcs/parsing/parsing_2.c srcs/parsing/parsing_3.c\
		srcs/utils/init_struct.c srcs/utils/exit_shell.c \
		srcs/execution/close_exec.c srcs/execution/env_for_execve.c \
		srcs/execution/exec_cmd.c srcs/execution/execution.c srcs/execution/ft_free_exec.c srcs/execution/pipes.c \
		srcs/execution/process.c srcs/execution/util_exec.c srcs/execution/ft_free.c \
		srcs/builtins/builtins.c srcs/builtins/echo.c srcs/builtins/export_utils.c srcs/builtins/export_var.c \
		srcs/builtins/export.c srcs/builtins/ft_cd.c srcs/builtins/ft_env.c srcs/builtins/unset.c srcs/builtins/ft_exit.c\
		srcs/builtins/ft_pwd.c \


CC=cc -g
FLAGS=-Wall -Werror -Wextra
NAME=minishell

%.o: %.c
	${CC} ${FLAGS} $< -o $@

${NAME} : ${LIBFT} ${SRCS}
	${CC} ${FLAGS} -lreadline -o ${NAME} ${SRCS} ${LIBFT}

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
