CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Contact.cpp Phonebook.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = Contact.hpp Phonebook.hpp
NAME = phonebook

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CFALGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re