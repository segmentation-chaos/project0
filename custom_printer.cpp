#include "custom_printer.hpp"

using namespace std;

Custom_Printer::Custom_Printer()
{
	printers.push_back(print_hello);
	printers.push_back(print_goodbye);
	printers.push_back(print_pedro);
	printers.push_back(print_jean);
}

Custom_Printer::Custom_Printer(const Custom_Printer &other)
{
	*this = other;
}

Custom_Printer& Custom_Printer::operator=(const Custom_Printer &other)
{
	if(this != &other)
	{
		printers.clear();
		for(unsigned int i = 0; i < other.size(); i++)
		{
			printers.push_back(other.get_printer(i));
		}
	}

	return *this;
}

Custom_Printer::~Custom_Printer()
{
}

int Custom_Printer::custom_print(int opt) const
{
	if(printers[opt]())
	{
		return 1;
	}

	return 0;
}

int (*Custom_Printer::get_printer(unsigned int i) const)()
{
	return printers[i];
}

unsigned int Custom_Printer::size() const
{
	return printers.size();
}

int Custom_Printer::print_hello()
{
	cout << "Hello, World!" << endl;

	return 0;
}

int Custom_Printer::print_goodbye()
{
	cout << "Goodbye, World!" << endl;

	return 0;
}

int Custom_Printer::print_pedro()
{
	/**
	 * Prints random characters a random number of times.
	 * Note that the modulo operation does not give a uniform distribution.
	 * Also, char implementation varies, which could result in non printable
	 * characters.
	 */
	srand(time(NULL));
	for(int i = 0; i < 1 + rand() % 80; i++)
	{
		cout << (char) (33 + rand() % 95);
	}
	cout << endl;

	return 0;
}

int Custom_Printer::print_jean()
{
	cout << "Vamo Inter!" << endl;

	return 0;
}
