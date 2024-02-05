#include "../../libs/Socket4Client.hpp"
#include "../../libs/program.hpp"


Socket4Client::Socket4Client(int client_socket) : _socket(client_socket) {
	this->_serverPath = "/srcs/program/server/var/www/webserver42";
	this->_contentType = "text/plain";
	this->_requestData = "";
	return ;
}

bool Socket4Client::isCGIRequest(std::string path) {
	size_t cgiDirPos = path.find("/cgi-bin/");

	if (cgiDirPos != std::string::npos) {
		return true;
	}

	return false;
}

void Socket4Client::handlerClient() {

	readRequest();
	getFilePath();


	if (isCGIRequest(_path)) {
		_filePath = getScriptPath(_path);
		_requestData = getRequestData();
		handleCGIRequest(_filePath, _requestData);
		_contentType = "text/html";
	} else {
		//logica per gestire GET POST and DELETE
		std::string basePath = std::getenv("PWD") + _serverPath;
		_filePath = basePath + _path;

		setContentType();
		readFileContent();
	}
	
	sendResponse();

	close(_socket);
}

void Socket4Client::readRequest() {

	while (true) {
		char		buffer[1024];
		int			bytes_read = read(_socket, buffer, sizeof(buffer) - 1);

		if (bytes_read == -1) {
			if (errno != EAGAIN && errno != EWOULDBLOCK) {
				perror("read");
			}
			break ;
		} else if (bytes_read == 0) {
			//Chiusura dal client
			break;
		}
		buffer[bytes_read] = 0;
		_request = buffer;
	}
}

void Socket4Client::getFilePath() {
	
	parseRequestLine();
	
	std::cout << _method << std::endl;
	std::cout << _path << std::endl;
	std::cout <<_filePath << std::endl;
}

void Socket4Client::readFileContent() {
	std::ifstream	file(_filePath.c_str(), std::ios::in | std::ios::binary);

	if (file) {
		file.seekg(0, std::ios::end);
		_fileContents.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&_fileContents[0], _fileContents.size());
		file.close();
	}
}

void Socket4Client::sendResponse() {
	
	std::ostringstream	response;
	std::string			responseStr;

	response << "HTTP/1.1 200 OK\r\n";
	response << "Content-Type: " << _contentType << "\r\n";
	response << "Content_Lenght: " << _fileContents.size() << "\r\n";
	response << "\r\n";
	response << _fileContents;

	responseStr = response.str();

	write(_socket, responseStr.c_str(), responseStr.size());
}

std::string Socket4Client::getScriptPath(const std::string& _path) {
	size_t startPos = _request.find(" ") + 1;
	size_t endPos = _request.find(" ", startPos);
	std::string url = _request.substr(startPos, endPos -startPos);

	std::map<std::string, std::string> cgiMappings;
	cgiMappings["/cgi-bin/hello_world_php.cgi"] = std::getenv("PWD") + _serverPath + "/cgi-bin/hello_world_php.cgi";
	cgiMappings["/cgi-bin/hello_world_perl.cgi"] = std::getenv("PWD") + _serverPath + "/cgi-bin/hello_world_perl.cgi";

	for (std::map<std::string, std::string>::iterator it = cgiMappings.begin(); it != cgiMappings.end(); ++it) {
		if (url.find(it->first) != std::string::npos) {
			return it->second;
		}
	}
	return "";
}

std::string Socket4Client::getRequestData() {
	size_t headerEnd = _request.find("\r\n\r\n");
	if (headerEnd != std::string::npos) {
		return _request.substr(headerEnd + 4);
	}

	return "";
}

void Socket4Client::parseRequestLine() {
	std::istringstream iss(_request);
	iss >> _method >> _path;
}

void Socket4Client::setContentType() {
	if (_filePath.find(".html") != std::string::npos) {
		_contentType = "text/html";
	} else if (_filePath.find(".css") != std::string::npos) {
		_contentType = "text/css";
	} else if (_filePath.find(".js") != std::string::npos) {
		_contentType = "application/javascript";
	}
}

void Socket4Client::handleCGIRequest(const std::string& scriptPath, const std::string& requestData) {
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
		dup2(pipe_fd[1], STDOUT_FILENO);
	
		close(pipe_fd[0]);
		close(pipe_fd[1]);

		char* argv[] = {const_cast<char*>(scriptPath.c_str()), NULL};

		execve(scriptPath.c_str(), argv, environ);

		perror("execve error");
		exit(0);
	} else {

		//Scrivi i dati della richiesta nel pipe se necessario
		if (!requestData.empty()) {
			write(pipe_fd[1], requestData.c_str(), requestData.size());
		}

		close(pipe_fd[1]);

		_fileContents = readFromPipe(pipe_fd[0]);

		close(pipe_fd[0]);

		waitpid(pid, NULL, 0);
	}
}

std::string Socket4Client::readFromPipe(int fileDescriptor) {
	std::string output;
	std::string buffer;
	char		buf[1024];
	int			bytesRead;

	while((bytesRead = read(fileDescriptor, buf, sizeof(buf) - 1)) > 0) {
		buf[bytesRead] = 0;
		output += buf;
	}

	return output;
}
