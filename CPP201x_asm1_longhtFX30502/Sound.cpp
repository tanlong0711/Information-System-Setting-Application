#include "Sound.h"


Sound::Sound()
{
	 mediaVolumeLevel=0;
	 callVolumeLevel=0;
	 notificationVolumeLevel=0;
	 navigationVolumeLevel=0;
}
Sound::~Sound() {}

void Sound::setMediaVolumeLevel(int level)
{
	this->mediaVolumeLevel = level;
}
int Sound::getMediaVolumeLevel() {
	return this->mediaVolumeLevel;
}

void Sound::setCallVolumeLevel(int level)
{
	this->callVolumeLevel = level;
}
int Sound::getCallVolumeLevel()
{
	return this->callVolumeLevel;
}

void Sound::setNotificationVolumeLevel(int level)
{
	this->notificationVolumeLevel = level;
}
int Sound::getNotificationVolumeLevel()
{
	return this->notificationVolumeLevel;
}

void Sound::setNavigationVolumeLevel(int level)
{
	this->navigationVolumeLevel = level;
}
int Sound::getNavigationVolumeLevel()
{
	return this->navigationVolumeLevel;
}

void Sound::inputMediaVolumeLevel()
{
	regex checkData("^(0|[1-9][0-9]*)$");
	string inputData;
	bool check = true;

	do
	{
		check = true;
		cout << "Enter the Media Volume Level: ";
		getline(cin, inputData);
		try
		{
			if (inputData.empty() || !regex_match(inputData, checkData)) {
				check == false;
				throw runtime_error( "Invalid value! Please enter the valid Media Volume Level.");
			}
			else setMediaVolumeLevel(stoi(inputData));
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
		
	} while (check==false);
}
void Sound::inputCallVolumeLevel() {
	regex checkData("^(0|[1-9][0-9]*)$");
	string inputData;
	bool check = true;

	do
	{
		check = true;
		cout << "Enter the Call Volume Level: ";
		getline(cin, inputData);
		try
		{
			if (inputData.empty() || !regex_match(inputData, checkData)) {
				check == false;
				throw runtime_error("Invalid value! Please enter the valid Call Volume Level.");
			}
			else setCallVolumeLevel(stoi(inputData));
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;

		}
		
	} while (check == false);
}
void Sound::inputNotificationVolumeLevel() {
	regex checkData("^(0|[1-9][0-9]*)$");
	string inputData;
	bool check = true;

	do
	{
		check = true;
		cout << "Enter the Notification Volume Level: ";
		getline(cin, inputData);
		try
		{
			if (inputData.empty() || !regex_match(inputData, checkData)) {
				check == false;
				throw runtime_error("Invalid value! Please enter the valid Notification Volume Level.");
			}
			else setNotificationVolumeLevel(stoi(inputData));
		}
		catch (const std::exception& e )
		{
			cout << e.what() << endl;
		}
		
	} while (check == false);
}
void Sound::inputNavigationVolumeLevel() {
	regex checkData("^(0|[1-9][0-9]*)$");
	string inputData;
	bool check = true;

	do
	{
		check = true;
		cout << "Enter the Navigation Volume Level: ";
		getline(cin, inputData);
		try
		{
			if (inputData.empty() || !regex_match(inputData, checkData)) {
				check == false;
				throw runtime_error("Invalid value! Please enter the valid Navigation Volume Level.");
			}
			else setNavigationVolumeLevel(stoi(inputData));
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;

		}
		
	} while (check == false);
}

// Hàm nhập thông tin Sound
void Sound::nhapThongTinSound() {
	inputMediaVolumeLevel();
	inputCallVolumeLevel();
	inputNotificationVolumeLevel();
	inputNavigationVolumeLevel();
}

// Hàm xuất thông tin Sound
void Sound::xuatThongTinSound()
{
	cout << left
		<< setw(20) << getMediaVolumeLevel()
		<< setw(20) << getCallVolumeLevel()
		<< setw(25) << getNotificationVolumeLevel()
		<< setw(20) << getNavigationVolumeLevel();
}