# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 01:16:53 by aperrone          #+#    #+#              #
#    Updated: 2023/05/05 01:16:55 by aperrone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombies
CC = c++
FLAGS = -Wall -Wextra -Werror
CCVERSION = -std=c++98
SRCs = srcs/*.cpp
OBJS = $(SRC:.cpp = .o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(CCVERSION) $(SRCs) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re