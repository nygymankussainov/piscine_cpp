#include "Logger.hpp"
#include <fstream>
#include <ctime>

Logger::Logger(std::string filename) : file(filename) {

	return;
}

Logger::~Logger( void ) {

	return;
}

void		Logger::logToConsole(std::string const & message) {

	std::cout << message << "\n";
}

void		Logger::logToFile(std::string const & message) {

	std::ofstream file(this->file, std::ios_base::app);
	file << message + "\n";
}

std::string	Logger::makeLogEntry(std::string message) {

	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	char tmp[100];
	strftime(tmp, sizeof(tmp), "[%d-%m-%Y %H:%M:%S] ", now);
	std::string date(tmp);
	message = date + message;
	return message;
}

void		Logger::log(std::string const & dest, std::string const & message) {

	std::string logEntry = this->makeLogEntry(message);
	void	(Logger::*funcptr[2])(std::string const & message) = { &Logger::logToConsole, &Logger::logToFile };
	std::string	dests[2] = { "logToConsole", "logToFile" };

	for (int i = 0; i < 2; ++i) {

		if (dest == dests[i])
			(this->*funcptr[i])(logEntry);
	}
}
