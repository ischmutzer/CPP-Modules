NAME = btc

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp\
BitcoinExchange.cpp

HEADERS = BitcoinExchange.hpp

OBJ := $(SRC:%.cpp=%.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CXX) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I./

debug:
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -g" re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

clear: all
	clear

run: all
	./$(NAME) text.txt

.PHONY: all clean fclean re clear run