SRCS=main.c parsing.c
CC=cc
FLAGS=-Wall -Werror -Wextra
NAME=philo_bonus
${NAME} : ${SRCS}
	${CC} ${FLAGS} -o ${NAME} ${SRCS}

all : ${NAME}

clean :

fclean : clean
	rm -f ${NAME}

re : fclean all
