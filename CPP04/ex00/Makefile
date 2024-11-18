NAME = Polymorphism

CXX = c++

FLAGS = -Wall -Werror -Wextra -Wshadow -Wno-shadow -std=c++98

SRC = main.cpp\
Animal.cpp\
Dog.cpp\
Cat.cpp\
WrongAnimal.cpp\
WrongCat.cpp

HEADERS = Animal.hpp\
Dog.hpp\
Cat.hpp\
WrongAnimal.hpp\
WrongCat.hpp

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