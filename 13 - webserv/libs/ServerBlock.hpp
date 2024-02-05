#ifndef SERVERBLOCK_HPP
# define SERVERBLOCK_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <algorithm>

# include <ParsedObj.hpp>

class ServerBlock : public ParsedObj {
	private:
		std::string _serverName;
		std::string _serverRootDir;
		std::string _defaultIndexName;
		std::fstream _defaultIndex; // da gestire come singleton
		std::list<int> _listenPorts;
		std::vector<std::string> _domainNames;

		ServerBlock(const ServerBlock &cpy);
		ServerBlock& operator=(const ServerBlock &cpy);
	public:
		ServerBlock();
		~ServerBlock();

		t_error eval(const std::string &what);
		void clear();
		int getListenPort() const;
		std::string getServerName() const;
};

#endif