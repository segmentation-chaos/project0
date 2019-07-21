#ifndef CUSTOM_PRINT_H
#define CUSTOM_PRINT_H

#include <iostream>
#include <vector>

class Custom_Printer
{
	public:
		int custom_print(int) const;
		unsigned int size() const;
		/* function returning a pointer to a function that returns an int */
		int (*get_printer(unsigned int) const)();

		/* constructor */
		Custom_Printer();
		/* copy constructor */
		Custom_Printer(const Custom_Printer&);
		/* copy assignment operator*/
		Custom_Printer& operator=(const Custom_Printer&);
		/* destructor */
		~Custom_Printer();
	private:
		/* an array of pointers to functions */
		std::vector<int (*)()> printers;

		static int print_hello();
		static int print_goodbye();
		static int print_david();
};

#endif
