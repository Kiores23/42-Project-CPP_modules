NAME = Polymorphisme
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp

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

re : fclean $(NAME)