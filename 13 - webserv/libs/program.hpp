#ifndef PROGRAM_HPP
# define PROGRAM_HPP

extern "C" {
	#include "libft.h"
}

# include <iostream>
# include <cerrno>
# include <vector>
# include <list>
# include <sstream>
# include <map>

# include <sys/socket.h>
# include <sys/select.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <netinet/tcp.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/poll.h>
# include <sys/epoll.h>
# include <sys/wait.h>

# include <ParsedObj.hpp>
# include <ServerBlock.hpp>

# include "SocketServer.hpp"
# include "Socket4Client.hpp"


# define ERR	"\033[0;31m"
# define OK		"\033[0;32m"
# define DEF	"\033[0m"

# define PORT	4242
# define MAX_POLL_FDS 100

# define CONF "conf/"


int	printErr(const char* msg);
int	printMsg(const char* msg);
int printMsgNoNl(const char* msg);


bool	invalidFileName(std::string _filename);

// Parser
t_error parseConfig(const std::string confPath, std::list<ServerBlock*> *confList);

#endif