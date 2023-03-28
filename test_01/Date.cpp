#include "Date.h"

Date::Date(int year)
{
	cout << "Date constructor called" << endl;
	Dyear = year;
}

void Date::Setdate(int year)
{
	Dyear = year;
}

void Date::Display()
{
	cout << Dyear << endl;
}
