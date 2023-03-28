#include "People.h"

People::People(string name, int year):Pbirth(year)
{
	cout << "People constructor called" << endl;
	Pname = name;
}

People::People(const People& peo)
{
	cout << "Copy constructor called";
}

void People::Setpeo(string name, int year)
{
	Pname = name;
	Pbirth.Setdate(year);
}

void People::Display()
{
	cout << Pname << "	";
	Pbirth.Display();
}
