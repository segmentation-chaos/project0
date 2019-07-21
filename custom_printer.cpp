#include "custom_printer.hpp"

using namespace std;

Custom_Printer::Custom_Printer()
{
	printers.push_back(print_hello);
	printers.push_back(print_goodbye);
	printers.push_back(print_david);
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
 
int Custom_Printer::print_david()
{
	cout << "\'Estar vivo parece siempre el precio de algo.\' (JC)." << endl;

	return 0;
}
