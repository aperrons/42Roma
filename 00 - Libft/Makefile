# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 09:37:55 by aperrone          #+#    #+#              #
#    Updated: 2023/03/13 02:35:37 by aperrone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

MAIN = main.c
INC = includes/program.h

SRCS = srcs/
LIBFT = libft/
LISTFT = listft/
PRGMFT = programft/
READ = -lreadline #-L/usr/include -lreadline -L$$HOME/.brew/opt/readline/lib -I $$HOME/.brew/opt/readline/include/readline
FILES = *.c
# INFO = "
# 	            _/\_/)
# 	           (),~  (
# 	   /\______///   \(
# 	 _/x       (/\    )'
# 	[_,        )==\  /
# 	  \ )_____(( (( /
# 	  |||   /// ///
# 	   ~    ~~  ~~
# \n\n"

FLAGS = -Wall -Wextra -Werror
DEBUGGER = -g

OBJS = *.o

$(OBJS):
	@gcc	$(READ) $(MAIN) \
			$(SRCS)$(LISTFT)$(FILES) \
			$(SRCS)$(LIBFT)$(FILES) \
			$(SRCS)$(PRGMFT)$(FILES) \
			-o $(NAME)
			@make -C ./builtins
#@echo	"\033[1;35mType ./piggyshell and the world will be yours!"

d:
	@gcc	$(DEBUGGER) $(READ) $(MAIN) \
			$(SRCS)$(LISTFT)$(FILES) \
			$(SRCS)$(LIBFT)$(FILES) \
			$(SRCS)$(PRGMFT)$(FILES) \
			-o $(NAME)
			@make -C ./builtins

$(NAME): 
	@make $(OBJS)
	@make clean

clean:
	@rm -f $(OBJS)

fclean: 
	@make clean
	@make fclean -C ./builtins
	@rm -f $(NAME)

re:
	@make fclean
	@make

pig:
	bash ./_piggyInf
	
.PHONY: all clean fclean