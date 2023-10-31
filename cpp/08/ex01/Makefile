NAME=span
CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
OBJDIR = .obj
SRCS=main.cpp Span.cpp
HEADERS=Span.hpp
OBJS=$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
all: $(NAME)
$(NAME): $(OBJS) $(HEADERS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
$(OBJDIR)/%.o: %.cpp $(HEADERS)
	mkdir -p $(dir $@)
	$(CPP) $(FLAGS) $(OPTS) -c $< -o $@
clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
