# I don’t want to set the world on fire
NAME = ex01
SRCS = Animal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Rules
all: $(NAME)

$(NAME):	$(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re