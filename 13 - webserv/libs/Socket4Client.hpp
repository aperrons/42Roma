#ifndef SOCKET4CLIENT_HPP
# define SOCKET4CLIENT_HPP

#include "program.hpp"

class Socket4Client {

	public:
		Socket4Client(int client_socket);

		bool		isCGIRequest(std::string path);
		void		handlerClient();
		void		readRequest();
		void		getFilePath();
		void		readFileContent();
		void		sendResponse();
		void		parseRequestLine();
		void		setContentType();


		std::string getScriptPath(const std::string& path);
		std::string	getRequestData();
		void		handleCGIRequest(const std::string& scriptPath, const std::string& requestData);
		std::string readFromPipe(int fileDescriptor);
		

	private:
		int			_socket;
		std::string _serverPath;
		std::string _request;
		std::string	_filePath;
		std::string _requestData;
		std::string	_fileContents;
		std::string _contentType;
		std::string	_path;
		std::string _method;
};



#endif