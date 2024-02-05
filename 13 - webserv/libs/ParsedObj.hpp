#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <list>

# include <string>
# include <sstream>


typedef short int t_error;


enum e_objType {
	NONE = -1,
	SERVERBLOCK,
	HTTPREQ,
};

/* Abstract Class for parsed objects */

class ParsedObj {
	private:
		std::string _objname;
		int _objtype;

	public:
		ParsedObj();
		ParsedObj(std::string name, int type);

		t_error eval(const std::string what);
		void clear()  {};
		void setObjName(const std::string name);
		std::string getObjName() const;
		int getObjType() const;
};

#endif 