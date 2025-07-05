CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = interface

SRCS =  main.cpp AMateria.cpp Cure.cpp IMateriaSource.cpp ICharacter.cpp MateriaSource.cpp Character.cpp Ice.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
