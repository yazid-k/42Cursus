SRCS=main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS=$(SRCS:.cpp=.o)
NAME=bsp
CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
all: $(NAME)
$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
