#include "../../libs/WebServer.hpp"

WebServer::WebServer(const int* ports, size_t numPorts) {
	for (size_t i = 0; i < numPorts; i++) {
		SocketServer *sserv = new SocketServer(ports[i]);
		servers.push_back(sserv);
	}
}

WebServer::~WebServer() {}

void WebServer::run() {
	while (true) {
		for (size_t i = 0; i < servers.size(); ++i) {
			servers[i]->run();
		}
	}
}