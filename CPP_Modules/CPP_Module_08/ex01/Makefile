NAME = Span
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Span.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
	@c++ -o $(NAME) $(OBJS)
	@echo « $(NAME) » was created

$(OBJS) : $(SRCS)
	@c++ $(FLAGS) -c $(SRCS)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)
	@echo « $(NAME) » was destroyed

re : fclean $(NAME)