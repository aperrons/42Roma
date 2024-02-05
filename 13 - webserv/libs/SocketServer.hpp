#ifndef SOCKETSERVER_HPP
# define SOCKETSERVER_HPP

#include "program.hpp"

class SocketServer {
	
	public:
		SocketServer(int port);
		~SocketServer();

		void	setNonBlocking(int socket);
		int		getListenFD();
		void	run();


	private:
		int					_server_fd;
		struct sockaddr_in	_address;
		int					_opt;
		int					_port;
		int					_epoll_fd;
		static const int	_MAX_EVENTS = 10;
};

#endif