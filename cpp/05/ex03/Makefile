SRCS=main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJS=$(SRCS:.cpp=.o)
NAME=forms
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
