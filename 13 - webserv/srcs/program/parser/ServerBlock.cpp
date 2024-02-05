#include <ServerBlock.hpp>


ServerBlock::ServerBlock() : ParsedObj("serverblock", SERVERBLOCK) {
	this->_serverName = "";
	this->_listenPorts = std::list<int>(1, -1);
}

ServerBlock::~ServerBlock() {}
ServerBlock::ServerBlock(const ServerBlock &cpy) : ParsedObj() {
	(void) cpy;
}

ServerBlock& ServerBlock::operator=(const ServerBlock &cpy) {
	(void) cpy;
	return *this;
}

t_error ServerBlock::eval(const std::string &what) {
	t_error 			error = 0;
	int					tmpInteger;
	std::string			tmpString;
	std::stringstream	ss;
	size_t 				endlinePos;
	
	endlinePos = what.find_first_of(";#\n");
	if (what.size() == 0 || endlinePos == std::string::npos) {
		return -1;
	}
	tmpString = what.substr(0, endlinePos);
	ss << tmpString;
	tmpString.clear();
	ss >> tmpString;
	if (tmpString.compare("server_names") == 0) {
		while (ss >> tmpString) {
			this->_domainNames.push_back(tmpString);
		}
		if (this->_domainNames.begin() == this->_domainNames.end()) {
			// ERROR No domain names associated (switch with throw?)
			error = 1;
		}
		else {
			this->_serverName = this->_domainNames.at(0);
		}
	}
	else if (tmpString.compare("listen") == 0) {
		while (ss >> tmpInteger) {
			if (tmpInteger < 1) {  
				//WARNING skipping port association (switch with throw?)
				;
			}
			else {
				this->_listenPorts.push_front(tmpInteger);
			}
		}
		if (*this->_listenPorts.begin() < 0) {
			// WARNING no ports associated (switch with throw?)
			error = 2;
		}
	}
	else if (tmpString.compare("host") == 0){
		;
	}
	else {
		// INFO unhandled parameter passed (switch with throw?)
		;
	}

	return error;
}

void ServerBlock::clear() {
	this->_serverName = "";
	this->_serverRootDir = "";
	this->_defaultIndexName = "";
	// this->_defaultIndex = NULL;
	this->_listenPorts.clear();
	this->_domainNames.clear();
}

int ServerBlock::getListenPort() const {
	return *this->_listenPorts.begin();
};

std::string ServerBlock::getServerName() const {
	return this->_serverName;
}