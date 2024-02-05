#include <iostream>
#include "../libs/program.hpp"
# include "../libs/WebServer.hpp"

int main(int ac, char **av) {
	
	if (ac != 2 || !av)
		return printErr("Requires 1 configuration file as argument");

	const int ports[] = {4242, 4243, 4244};
	
	WebServer webServer(ports, 3);
	webServer.run();
	
	return 0;
}