SRCSLIB=libft/ft_atoi.c libft/ft_strdup.c libft/ft_bzero.c libft/ft_putendl_fd.c libft/ft_isalnum.c\
		libft/ft_strnstr.c libft/ft_isalpha.c libft/ft_putnbr_fd.c libft/ft_striteri.c libft/ft_split.c\
		libft/ft_isascii.c libft/ft_memchr.c libft/ft_strjoin.c libft/ft_isdigit.c libft/ft_memcmp.c\
		libft/ft_putstr_fd.c libft/ft_strlcat.c libft/ft_substr.c libft/ft_isprint.c libft/ft_memcpy.c\
		libft/ft_strlen.c libft/ft_strtrim.c libft/ft_itoa.c libft/ft_strchr.c libft/ft_tolower.c\
		libft/ft_memmove.c libft/ft_strmapi.c libft/ft_toupper.c libft/ft_memset.c libft/ft_strncmp.c\
		libft/ft_putchar_fd.c libft/ft_strrchr.c libft/ft_strlcpy.c libft/ft_calloc.c libft/ft_lstnew.c\
		libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c\
		libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c libft/get_next_line.c\
		libft/ft_put_addr_fd.c libft/ft_put_base_fd.c libft/ft_printf.c

SRCSSERV=server.c

SRCSCLIENT=client.c

OBJSLIB=${SRCSLIB:.c=.o}

FLAGS=-Wall -Werror -Wextra

CC=gcc

SERVER=server
CLIENT=client
LIBFT=libft.a

all : ${SERVER} ${CLIENT}

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${SERVER} : ${LIBFT} ${SRCSSERV}
	${CC} ${FLAGS} -o ${SERVER} ${SRCSSERV} ${LIBFT}

${CLIENT} : ${LIBFT} ${SRCSCLIENT}
	${CC} ${FLAGS} -o ${CLIENT} ${SRCSCLIENT} ${LIBFT}

${LIBFT} : ${OBJSLIB}
	ar rc ${LIBFT} ${OBJSLIB}

cleanlib :
	rm -f ${OBJSLIB}

clean : cleanlib

fclean : clean
	rm -f ${CLIENT} ${SERVER} ${LIBFT}

re : fclean all

.phony : server client
