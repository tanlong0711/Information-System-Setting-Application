#pragma once
#include <string>
#include <iostream>
#include <regex>
#include "Common.h"
#include <iomanip>

using namespace std;
class General
{
	string timeZone;
	string language;
public:
	General();
	~General();

	void setTimeZone(string timeZone);
	string getTimeZone();

	void setLanguage(string language);
	string getLanguage();

	void inputTimezone();
	void inputLanguage();
	
	//Nhập thông tin cho General
	void nhapThongTinGeneral();

	// Xuất thông tin General
	void xuatThongTinGeneral();
};


