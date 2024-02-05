#include "../libs/program.hpp"

int printErr(const char* msg) {
	std::cerr << ERR << msg << DEF << std::endl;
	return 1;
}

int printMsg(const char* msg) {
	std::cerr << OK << msg << DEF << std::endl;
	return 1;
}

bool invalidFileName(std::string _filename) {
	size_t dotPos = _filename.find_last_of(".");
	if (dotPos == std::string::npos)
		return true;
	if (_filename.compare(dotPos, _filename.npos, ".conf"))
		return true;
	return false;
}