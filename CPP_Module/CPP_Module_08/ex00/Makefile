CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = easyfind.hpp
NAME =  easyfind

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
