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
	./$(NAME)

.PHONY: all clean fclean re run