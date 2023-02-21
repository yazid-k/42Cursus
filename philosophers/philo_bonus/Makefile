SRCS=main.c parsing.c utils.c
CC=cc
FLAGS=-Wall -Werror -Wextra
NAME=philo
${NAME} : ${SRCS}
	${CC} ${FLAGS} -o ${NAME} ${SRCS}

all : ${NAME}

clean :

fclean : clean
	rm -f ${NAME}

re : fclean all
