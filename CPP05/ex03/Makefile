NAME = intern

CXX = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp\
Bureaucrat.cpp\
Form.cpp\
ShrubberyCreationForm.cpp\
RobotomyRequestForm.cpp\
PresidentialPardonForm.cpp\
Intern.cpp


HEADERS = Bureaucrat.hpp\
Form.hpp\
ShrubberyCreationForm.hpp\
RobotomyRequestForm.hpp\
PresidentialPardonForm.hpp\
Intern.hpp

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