#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP

#include "program.hpp"

class WebServer {

	public:
		WebServer(const int* ports, size_t numPorts);
		~WebServer();

		void run();

	private:
		std::vector<SocketServer*> servers;
};

#endif