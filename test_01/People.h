#pragma once
#include"Date.h"
#include<string>
class People
{
	string Pname;
	Date Pbirth;
public:
	People(string name, int year);
	void Setpeo(string name, int year);
	void Display();
};