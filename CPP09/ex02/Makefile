NAME = PmergeMe

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = main.cpp\
PmergeMe.cpp

HEADER = PmergeMe.hpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME) 14 3 27 9 10

#####################
N = 500
test:			all
					./$(NAME) `shuf -i 1-100000000 -n $(N) | tr "\n" " "`

test5:			all
					./$(NAME) `shuf -i 1-50 -n 5 | tr "\n" " "`

fix5:			all
					./$(NAME) 44 28 4 11 6

test6:			all
					./$(NAME) 8 3 1 5 9 2 

test10:			all
					./$(NAME) `shuf -i 1-10 -n 10 | tr "\n" " "`

valgrindtest:	all
					valgrind ./$(NAME) `shuf -i 1-10000 -n $(N) | tr "\n" " "`

###########################


.PHONY: all clean fclean re run