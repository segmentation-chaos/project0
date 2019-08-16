#include "custom_printer.hpp"

using namespace std;

Custom_Printer::Custom_Printer()
{
	printers.push_back(print_hello);
	printers.push_back(print_goodbye);
	printers.push_back(print_vitor);
	printers.push_back(print_david);
	printers.push_back(print_pedro);
	printers.push_back(print_jean);
	printers.push_back(print_geovane);
	printers.push_back(print_palmero);
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

int Custom_Printer::print_vitor()
{
  /*
  * Last paragraph of Casino Royale novel by Ian Flaming
  */
	cout << "This is 007 speaking. This is an open line. It's an emergency.";
	cout << "Can you hear me? Pass this at once.";
	cout << "3030 was a double, working for Redland.";
	cout << "Yes, dammit, I said was. The bitch is dead now." << endl;
	
	return 0;
}
 
int Custom_Printer::print_david()
{
	cout << "\'Estar vivo parece siempre el precio de algo.\' (JC)." << endl;
  
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

int Custom_Printer::print_geovane()
{
	cout << "Não me segue que to perdido!" << endl;

	return 0;
}

int Custom_Printer::print_palmero()
{
	string answer;
	cout << "Quero testar um role, vamo ver.";
	cout << "\nSe quiser mesmo ver o que escrevi, digite 'yes'." << endl;
	cin >>  answer;
	while("yes" != answer &&  "no" != answer)
	{
		cout  << "Escreve certinho, 'yes'.";
		cout << "\nMas, se quiser sair, digite 'no'." << endl;
		cin >> answer; 
	}
	
	if("yes" == answer)
	{
		cout << "Valeu ae, só era pra testar mesmo ^^" << endl;
	}
	else if("no" == answer)
	{
		cout << "De boa, um abraço!" << endl;
	}

	return 0;
}
