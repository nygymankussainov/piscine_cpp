#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>

class Logger {

public:

	std::string file;

	Logger(std::string filename);
	~Logger( void );

	void		log(std::string const & dest, std::string const & message);

private:

	void		logToConsole(std::string const & message);
	void		logToFile(std::string const & message);
	std::string	makeLogEntry(std::string message);
};

#endif
