#include "General.h"
extern vector<Common> listLanguage;
extern vector< Common> listTimeZone;

General::General()
{
	timeZone = "(GMT+07:00)";
	language = " Vietnamese";
}
General::~General(){}

void General::setTimeZone(string data)
{
	this->timeZone = data;
}
string General::getTimeZone()
{
	return this->timeZone;
}

void General::setLanguage(string data)
{
	this->language = data;
}
string General::getLanguage()
{
	return this->language;

}

void General::inputTimezone() {
	regex checkData("^[1-9]$|^[1-2][0-9]$|^3[0-2]$");
	string inputData = "";
	bool check = true;

	// Display list TimeZones
	for (int i = 0; i < listTimeZone.size(); i++)
	{
		cout << i + 1 << ". ";
		cout << (i >=9 ? "" : " ");
		cout << listTimeZone.at(i).getNumber() << " : " << listTimeZone.at(i).getName() << endl;
	}

	do
	{
		check = true;
		cout << "Enter the TimeZone: ";
		getline(cin, inputData);
		try
		{
			if (inputData.empty() || !regex_match(inputData, checkData)) {
				check = false;
				throw runtime_error("Invalid input!! Please enter a valid timezone selection from 1-32.");
			}
			else {
				setTimeZone(listTimeZone.at(stoi(inputData) - 1).getNumber());
			}
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}
		
	} while (check == false);
}
void General::inputLanguage() {
	regex checkData("^[1-9]$|^[1-2][0-9]$|^3[0]$");
	string inputData = "";
	bool check = true;

	for (int i = 0; i < listLanguage.size(); i++)
	{
		cout << i + 1 << ". ";
		cout << (i >= 9 ? "" : " ");
		cout<< listLanguage.at(i).getName() << endl;
	}

	do
	{
		check = true;
		cout << "Enter the Language: ";
		getline(cin, inputData);
		try
		{
			if (inputData.empty() || !regex_match(inputData, checkData)) {
				check = false;
				throw runtime_error("Invalid value! Please enter the valid Language from 1-30.");
			}
			else setLanguage(listLanguage.at(stoi(inputData) - 1).getName());
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}
		
	} while (check == false);
}

//Nhập thông tin cho General
void General::nhapThongTinGeneral() {
	inputTimezone();
	system("cls");
	inputLanguage();
}

// Xuất thông tin General
void General::xuatThongTinGeneral()
{
	cout << left
		<< setw(20) << getTimeZone()
		<< getLanguage();
}

