#include "custom_printer.hpp"

/**
 * The main function receives the arguments from the shell call.
 * argc is the number of arguments passed in the call.
 * argv holds the various arguments as arrays of characters (with the first
 * being the name of the executable).
 */
int main(int argc, char **argv)
{
	Custom_Printer cp;

	cp.custom_print(0);

	/* Returning 0 is a sign of successful execution. */
	return 0;
}
