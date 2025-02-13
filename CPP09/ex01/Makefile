NAME = RPN

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp\
RPN.cpp

HEADER = RPN.hpp

OBJS = $(SRCS:.cpp=.o)

RM: rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o = %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run