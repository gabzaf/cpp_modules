NAME = btc

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

CC = c++
CPP_FLAGS = -g -O0 -Wall -Wextra -Werror
CC_FLAGS = -std=c++98 -pedantic-errors 

$(NAME): $(OBJS)
	$(CC) $(CPP_FLAGS) $(CC_FLAGS) *.o -o $(NAME)

%.o: %.cpp
	$(CC) $(CPP_FLAGS) $(CC_FLAGS) -c $< -o $@

valgrind: $(NAME)
	valgrind --leak-check=full \
	         --show-leak-kinds=all \
	         --track-origins=yes \
	         --log-file=valgrind-out.txt \
	         ./$(NAME) input.csv

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME) valgrind-out.txt

re: fclean all

.PHONY: all clean fclean re
