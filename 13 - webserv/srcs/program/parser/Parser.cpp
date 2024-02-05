#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <list>

#include <program.hpp>

enum e_blockState {
	UNKNOWN = -1,
	INITIALIZED,
	BUILDING,
	COMPLETED
};

void strSanitize(std::string &s) {
	std::stringstream ss(s);
	std::string tmp("");

	if (s.length() == 0) {
		return ;
	}
	s = tmp;
	while (ss >> tmp) {
		if (tmp.compare("#") == 0)
			break;
		if (s.size() > 0) {
			s += " ";
		}
		s += tmp;
	}
}

t_error parseLocation(std::string line, ServerBlock *&block, std::ifstream &confFile) {
	(void) block; // placeholder
	
	while (std::getline(confFile, line)) {
		if (line.find_first_of("}") != std::string::npos) {
			break;
		}
	}
	return 0;
}

t_error parseConfig(const std::string confPath, std::vector<ServerBlock*> *confVec) {
	std::ifstream confFile(confPath.c_str());
	std::string line;
	int blockState = UNKNOWN;
	t_error error = 0;

	if (!confFile.is_open()) {
		return -1;
	}

	while (std::getline(confFile, line)) {
		strSanitize(line);
		if (line.find("server") == 0 && line.find("server_") != 0) {
			if (blockState == UNKNOWN || blockState == COMPLETED)
				confVec->push_back(new ServerBlock());
			else {
				confVec->back()->clear();
			}
			blockState = INITIALIZED;
			if (line.find_first_of("{") != std::string::npos) {
				line = line[line.find_first_of("{")];
			}
		}
		if (line.find_first_of("{") == 0) {
			blockState = BUILDING;
		}
		if (blockState == BUILDING) {
			if (line.find("location") == 0) {
				error = parseLocation(line, confVec->back(), confFile);
				line = "";
			}
			else {
				confVec->back()->eval(line);
			}
			if (line.find_first_of("}") == 0) {
				blockState = COMPLETED;
			}
		}
	}
	confFile.close();
	return error;
}