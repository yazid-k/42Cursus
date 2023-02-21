SRCS=main.c parsing.c utils_1.c utils_2.c actions.c
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
