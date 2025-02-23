

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 

SRCS =  
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compiling .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
