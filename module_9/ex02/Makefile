NAME = PmergeMe

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror
CPP_FLAGS = -std=c++98 -pedantic-errors 

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(CPP_FLAGS) *.o -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $(CPP_FLAGS) -c $< -o $@

all: $(NAME)

# Usage: make valgrind ARGS="$(shuf -i 1-5000 -n 100 | tr '\n' ' ')"
valgrind: $(NAME)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         --log-file=valgrind-out.txt \
	         ./$(NAME) $(ARGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) valgrind-out.txt

re: fclean all

.PHONY: all clean fclean re
