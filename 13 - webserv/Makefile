NAME = webserv

# Keep different names for files
SRCS := $(wildcard  \
	./web_cgi/srcs/*.cpp\
	./srcs/program/*.cpp\
	./srcs/program/*/*.cpp\
	)

OBJS = $(SRCS:.cpp=.o)

CC = c++ -std=c++98
#FLAGS = -Wall -Wextra -Werror -I./libs
FLAGS = -I./libs

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(SRCS) $(FLAGS) -o $(NAME) &&\
	chmod +x $(NAME)

%.o : %.cpp
	$(CC) -c $(FLAGS) -o $@ $< 

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
