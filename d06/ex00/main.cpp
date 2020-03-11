#include "Conversion.hpp"

int		main(int argc, char **argv) {

	Conversion conv;
	double value;

	if ( argc == 2 ) {

		value = static_cast<double> (atof(argv[argc - 1]));
		conv.convertToChar(value);
		conv.convertToInt(value);
		conv.convertToFloat(value);
		conv.convertToDouble(value);
	}
	return 0;
}
