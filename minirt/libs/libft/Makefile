SRCS= ft_atoi.c ft_strdup.c ft_bzero.c ft_putendl_fd.c ft_isalnum.c ft_strnstr.c\
		ft_isalpha.c ft_putnbr_fd.c ft_striteri.c ft_split.c ft_isascii.c ft_memchr.c\
		ft_strjoin.c ft_isdigit.c ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_substr.c\
		ft_isprint.c ft_memcpy.c ft_strlen.c ft_strtrim.c ft_itoa.c ft_strchr.c\
		ft_tolower.c ft_memmove.c ft_strmapi.c ft_toupper.c ft_memset.c ft_strncmp.c ft_strcmp.c\
		ft_putchar_fd.c ft_strrchr.c ft_strlcpy.c ft_calloc.c\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c\
		ft_put_addr_fd.c ft_put_base_fd.c ft_printf.c ft_atof.c


OBJS=${SRCS:.c=.o}

FLAGS=-Wall -Wextra -Werror -c

CC = gcc

NAME = libft.a

.c.o :
	${CC} ${FLAGS} $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
