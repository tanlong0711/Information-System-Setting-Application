#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class Common
{
	string number;
	string name;
public:
	Common();
	~Common();

	void setNumber(string data);
	string getNumber();

	void setName(string data);
	string getName();
};

