#pragma once
#include<iostream>
using namespace std;
class Date {
	int Dyear;
public:
	Date(int year = 2022);
	void Setdate(int year);
	void Display();
};