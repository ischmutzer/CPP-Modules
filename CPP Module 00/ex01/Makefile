NAME = phonebook

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = Phonebook.hpp

SRC = .cpp

OBJ := $(SRC:%.cpp=%.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CXX) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(CXX) $(FLAGS) -c $< -o $@ -I./

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
