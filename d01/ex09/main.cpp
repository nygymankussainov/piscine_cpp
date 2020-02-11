#include "Logger.hpp"

int		main( void ) {

	Logger log("test");

	log.log("logToConsole", "Hello");
	log.log("logToFile", "Hello");
	return 0;
}
