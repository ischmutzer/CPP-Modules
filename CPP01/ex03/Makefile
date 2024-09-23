NAME = violence

CXX = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = HumanA.cpp\
HumanB.cpp\
main.cpp\
Weapon.cpp

HEADERS = HumanA.hpp\
HumanB.hpp\
Weapon.hpp

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

clear: all
	clear

run: all
	./$(NAME)

.PHONY: all clean fclean re clear run