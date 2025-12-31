NAME = btc

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

CC = c++
CPP_FLAGS = -Wall -Wextra -Werror
CC_FLAGS = -std=c++98 -pedantic-errors -fsanitize=address

$(NAME): $(OBJS)
	$(CC) $(CPP_FLAGS) $(CC_FLAGS) *.o -o $(NAME)

%.o: %.cpp
	$(CC) $(CPP_FLAGS) $(CC_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
