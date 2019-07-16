#include <unistd.h>

#include <cstdlib>

#include "custom_printer.hpp"

using namespace std;

/**
 * The main function receives the arguments from the shell call.
 * argc is the number of arguments passed in the call.
 * argv holds the various arguments as arrays of characters (with the first
 * being the name of the executable).
 */
int main(int argc, char **argv)
{
	int c = 0;
	int m = 0;
	Custom_Printer cp;

	while ((c = getopt(argc, argv, "hm:")) != -1)
	{
		switch(c)
		{
			case 'm':
				m = atoi(optarg);

				if(cp.size() <= (unsigned int) m)
				{
					cerr << "Error: ";
					cerr << "Option -m requires a positive integer below ";
					cerr << cp.size() << endl;

					return 2;
				}

				break;
			case 'h':
				cout << "Usage: " << argv[0];
				cout << " [-m 0";
				for(unsigned int i = 1; i < cp.size(); i++)
				{
					cout << "|" << i;
				}
				cout << "]" << endl;

				return 0;
			case '?':

				return 2;
		}
	}

	cp.custom_print(m);

	/* Returning 0 is a sign of successful execution. */
	return 0;
}
