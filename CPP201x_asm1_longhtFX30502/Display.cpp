#include "Display.h"

Display::Display()
{
	lightLevel = 0;
	screenLightLevel = 0;
	taploLightLevel = 0;
}
Display::~Display() {}

void Display::setLightLevel(int lightLevel)
{
	this->lightLevel = lightLevel;
}
int Display::getLightLevel()
{
	return this->lightLevel;
}

void Display::setScreenLightLevel(int screenLightLevel)
{
	this->screenLightLevel = screenLightLevel;
}
int Display::getScreenLightLevel()
{
	return this->screenLightLevel;
}

void Display::setTaploLightLevel(int taploLightLevel)
{
	this->taploLightLevel = taploLightLevel;

}
int Display::getTaploLightLevel()
{
	return this->taploLightLevel;
}

// Nhập input cho các biến
void Display::inputLightLevel()
{
	regex checkinput("^(0|[1-9][0-9]*)$");
	string lightInput;
	bool check = true;
	do
	{
		check = true;
		cout << "Enter the Light Level: ";
		getline(cin, lightInput);
		try
		{
			if (lightInput.empty() || !regex_match(lightInput, checkinput)) {
				check = false;
				cout << "Invalid value! Please enter the valid Light Level" << endl;
			}
			else {
				setLightLevel(stoi(lightInput));
			}
		}
		catch (const out_of_range&)
		{
			cout << "Invalid input!! Please enter a valid light level.\n";
		}
	} while (check==false);
}
void Display::inputScreenLightLevel()
{
	regex checkinput("^(0|[1-9][0-9]*)$");
	string screenLightInput;
	bool check = true;
	do
	{
		check = true;
		cout << "Enter the Screen Light Level: ";
		getline(cin, screenLightInput);
		try
		{
			if (screenLightInput.empty() || !regex_match(screenLightInput, checkinput)) {
				check = false;
				cout << "Invalid value! Please enter the valid Screen Light Level" << endl;
			}
			else {
				setScreenLightLevel(stoi(screenLightInput));
			}
		}
		catch (const out_of_range&)
		{
			cout << "Invalid input!! Please enter a valid light level.\n";
		}
		
	} while (check == false);
}
void Display::inputTaploLightLevel()
{
	regex checkinput("^(0|[1-9][0-9]*)$");
	string taploLightInput;
	bool check = true;
	do
	{
		check = true;
		cout << "Enter the Taplo Light Level: ";
		getline(cin, taploLightInput);
		try
		{
			if (taploLightInput.empty() || !regex_match(taploLightInput, checkinput)) {
				check = false;
				cout << "Invalid value! Please enter the valid Taplo Light Level" << endl;
			}
			else {
				setTaploLightLevel(stoi(taploLightInput));
			}
		}
		catch (const out_of_range&)
		{
			cout << "Invalid input!! Please enter a valid light level.\n";
		}
		
	} while (check == false);
}

// Nhập thông tin Display
void Display::nhapThongTinDisplay()
{
	inputLightLevel();
	inputScreenLightLevel();
	inputTaploLightLevel();
}

//Xuất thông tin Display
void Display::xuatThongTinDisplay() {
	cout << left
		<< setw(20) << getLightLevel()
		<< setw(20) << getScreenLightLevel()
		<< setw(20) << getTaploLightLevel();
}
