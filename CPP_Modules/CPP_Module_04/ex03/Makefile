NAME = Interface_and_recap
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		Character.cpp \
		Inventory.cpp \
		MateriaSource.cpp

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