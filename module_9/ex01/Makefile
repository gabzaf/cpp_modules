NAME = RPN

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror
CPP_FLAGS = -std=c++98 -pedantic-errors -fsanitize=address

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(CPP_FLAGS) *.o -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $(CPP_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
