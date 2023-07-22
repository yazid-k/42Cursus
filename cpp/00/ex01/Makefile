NAME=phonebook
SRCS=Contact.cpp PhoneBook.cpp main.cpp
CPP=c++
FLAGS=-std=c++98
all: $(NAME)
$(NAME): $(SRCS)
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)
clean:
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
