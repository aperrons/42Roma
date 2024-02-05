# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 01:18:52 by aperrone          #+#    #+#              #
#    Updated: 2023/05/05 01:18:53 by aperrone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sed4losers
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
	rm -f *.replace

re: fclean all

.PHONY: all clean fclean re