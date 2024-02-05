#include "../../libs/SocketServer.hpp"

SocketServer::SocketServer(int port) : _port(port), _opt(1) {

	//Creazione del socket del server
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	std::cout << _server_fd << " " << _port << std::endl;
	if (_server_fd == 0) {
		printErr("Server socket failed.");
		exit(0);
		//return (EXIT_FAILURE);
	}
	
	//Configurazione socket
	if (setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &_opt, sizeof(_opt))) {
		printErr("Setsockopt failed.");
		exit(0);
		//return (EXIT_FAILURE);
	}

	_address.sin_family = AF_INET;
	_address.sin_addr.s_addr = INADDR_ANY;
	_address.sin_port = htons(_port);

	//Binding del socket
	if (bind(_server_fd, (struct sockaddr *)&_address, sizeof(_address)) < 0) {
		printErr("Server binding failed");
		exit(0);
		//return (EXIT_FAILURE);
	}

	//Inizio listening
	if (listen(_server_fd, 10) < 0) {
		printErr("Listening failed");
		exit(0);
		//return (EXIT_FAILURE);
	}

	setNonBlocking(_server_fd);

	//epoll setup
	_epoll_fd = epoll_create(_MAX_EVENTS);
	if (_epoll_fd == -1) {
		printErr("epoll_create failed.");
		exit(0);
		//return (EXIT_FAILURE);
	}

	struct epoll_event event;
	memset(&event, 0, sizeof(event));
	event.data.fd = _server_fd;
	event.events = EPOLLIN;
	if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _server_fd, &event) == -1) {
		printErr("epoll_ctl: server_fd failed.");
		exit(0);
		//return (EXIT_FAILURE);
	}
}

void SocketServer::run() {
	struct epoll_event events[_MAX_EVENTS];
	int n = epoll_wait(_epoll_fd, events, _MAX_EVENTS, 10);

	for (int i = 0; i < n; i++) {
		if (events[i].data.fd == _server_fd) {
			struct sockaddr_in client_addr;
			socklen_t client_addr_len = sizeof(client_addr);
			int client_fd = accept(_server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

			if (client_fd != -1) {
				setNonBlocking(client_fd);
				struct epoll_event client_event;
				memset(&client_event, 0, sizeof(client_event));
				client_event.data.fd = client_fd;
				client_event.events = EPOLLIN | EPOLLET;

				if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, client_fd, &client_event) == -1) {
					perror("epoll_ctl: client_fd added");
					close(client_fd);
				}
			}
		} else {
			Socket4Client socketClient(events[i].data.fd);
			socketClient.handlerClient();
		}
	}
}

SocketServer::~SocketServer() {
	close(_server_fd);
	close(_epoll_fd);
}

void SocketServer::setNonBlocking(int socket) {
	int flags = fcntl(socket, F_GETFL, 0);

	if (flags == -1) {
		printErr("fcnt_cntl F_GET failed.");
		exit(0);
	}
	if (fcntl(socket, F_SETFL, flags | O_NONBLOCK) == 1) {
		printErr("F_SET NONBLOCK failed.");
		exit(0);
	}
}

int SocketServer::getListenFD() {
	return _server_fd;
}
/*
void SocketServer::handleCGIRequest(int client_fd, const std::string& scriptPath, const std::string& requestData) {
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1) {
		perror("Pipe error");
		return ;
	}

	pid_t pid = fork();
	if (pid == -1) {
		perror("Fork error");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return ;
	}

	if (pid == 0) {
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(client_fd, STDOUT_FILENO);

		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(client_fd);

		char* argv[] = {const_cast<char*>(scriptPath.c_str()), NULL};
		execve(scriptPath.c_str(), argv, environ);

		perror("execve error");
		exit(0);
	} else {
		//Chiudi lato lettura pipe genitore
		close(pipe_fd[0]);

		//Scrivi i dati della richiesta nel pipe se necessario
		if (!requestData.empty()) {
			write(pipe_fd[1], requestData.c_str(), requestData.size());
		}

		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
	}
}*/