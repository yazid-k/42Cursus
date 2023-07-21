NAME=megaphone
CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
all: $(NAME)
$(NAME): megaphone.cpp
	$(CPP) $(FLAGS) megaphone.cpp -o $(NAME)
clean:
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
