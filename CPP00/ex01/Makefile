NAME = phonebook

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = Phonebook.hpp

SRC = Phonebook.cpp\
Contacts.cpp\
main.cpp

OBJ := $(SRC:%.cpp=%.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CXX) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(CXX) $(FLAGS) -c $< -o $@ -I./

clean:
	$(RM) $(OBJ)

run: all
	./$(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

clear: all
	clear

.PHONY: all clean fclean re
