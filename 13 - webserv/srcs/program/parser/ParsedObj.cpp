#include <ParsedObj.hpp>

ParsedObj::ParsedObj() : _objname("none"), _objtype(NONE) {}
ParsedObj::ParsedObj(std::string name, int type) : _objname(name), _objtype(type) {}

void ParsedObj::setObjName(const std::string name) {
	this->_objname = name;
}

t_error ParsedObj::eval(const std::string what) {
	(void) what;
	return 0;
}

std::string ParsedObj::getObjName() const {
	return this->_objname;
}

int ParsedObj::getObjType() const {
	return this->_objtype;
}