# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 20:58:01 by aperrone          #+#    #+#              #
#    Updated: 2023/05/04 20:58:03 by aperrone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
FLAGS = -Wall -Wextra -Werror
CCVERSION = -std=c++98
SRCs = *.cpp
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