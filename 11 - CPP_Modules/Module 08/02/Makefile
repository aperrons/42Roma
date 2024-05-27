NAME = mutated
CC = c++
FLAGS = -Wall -Wextra -Werror
CCVERSION = -std=c++98
OBJS = $(SRC:.cpp = .o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(CCVERSION) main.cpp -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re