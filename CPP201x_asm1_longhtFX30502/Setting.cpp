#include "Setting.h"

Setting::Setting() { //This constructor allows the Setting object to access the other object's properties
	myDisplay = new Display();
	mySound = new Sound();
	myGeneral = new General();
}

Setting::~Setting() {
	delete myDisplay;
	delete mySound;
	delete myGeneral;
}


Display* Setting::getDisplay() // Hàm truy cập obj từ bên ngoài
{
	return myDisplay;
}
void Setting::setDisplay(Display* display) // Hàm để set obj
{
	this->myDisplay = display;
}

Sound* Setting::getSound()
{
	return mySound;

}
void Setting::setSound(Sound* sound)
{
	this->mySound = sound;
}

General* Setting::getGeneral()
{
	return myGeneral;
}
void Setting::setGeneral(General* general) {
	this->myGeneral = general;
}


void Setting::convertInfor(Setting* set) {
	setOwnerName(set->getOwnerName());
	setMSCN(set->getMSCN());
	setEmail(set->getEmail());
	setOdo(set->getOdo());
	setRemindService(set->getRemindService());
}

void Setting::converInforDisplay(Setting* set)
{
	myDisplay->setLightLevel(set->getDisplay()->getLightLevel());
	myDisplay->setTaploLightLevel(set->getDisplay()->getTaploLightLevel());
	myDisplay->setScreenLightLevel(set->getDisplay()->getScreenLightLevel());
}
void Setting::converInforSound(Setting* set)
{
	mySound->setMediaVolumeLevel(set->getSound()->getMediaVolumeLevel());
	mySound->setCallVolumeLevel(set->getSound()->getCallVolumeLevel());
	mySound->setNavigationVolumeLevel(set->getSound()->getNavigationVolumeLevel());
	mySound->setNotificationVolumeLevel(set->getSound()->getNotificationVolumeLevel());
}
void Setting::converInforGeneral(Setting* set) {
	myGeneral->setLanguage(set->getGeneral()->getLanguage());
	myGeneral->setTimeZone(set->getGeneral()->getTimeZone());
}
void Setting::converInforFull(Setting &set) // đổi chỗ thông tin 2 obj
{
	setOwnerName(set.getOwnerName());
	setMSCN(set.getMSCN());
	setOdo(set.getOdo());
	setEmail(set.getEmail());
	setRemindService(set.getRemindService());
	setDisplay(set.getDisplay());
	setSound(set.getSound());
	setGeneral(set.getGeneral());
}

void Setting::inputOwnerName()
{
	regex checkName("^[A-Za-z\\s]+$");
	string name = "";
	bool check = true;
	do
	{
		check = true;
		cout << "Enter ownerName: ";
		getline(cin, name);
		try
		{
			if (name.empty() || !regex_match(name, checkName)) {
				check = false;
				throw runtime_error("Invalid value! Please enter a valid name.");
			}
			else setOwnerName(name);
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
		
	} while (check==false);
}
void Setting::inputEmail()
{
	regex checkMail(R"(\b[A-Za-z0-9_]{3,}@[A-Za-z0-9]{3,8}\.[A-Za-z]{3,}\b)"); //follows email@abc.xyz format
	string email = "";
	bool check = true;

	do
	{
		check = true;
		cout << "Enter the email address: ";
		getline(cin, email);
		try
		{
			if (email.empty() || !regex_match(email, checkMail))
			{
				check = false;
				throw runtime_error("Invalid Value! Please enter vilid email.");
			}
			else setEmail(email);
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	} while (check==false);
}
void Setting::inputMSCN()
{
	regex MSCN("^[0-9]{8}$");
	string mscn;
	bool check = true;
	do
	{

		check = true;
		cout << "Enter the Key number: ";
		getline(cin, mscn);
		try
		{
			if (mscn.empty() || !regex_match(mscn, MSCN))
			{
				check = false;
				throw runtime_error("Invalid value! Please enter the valid Key number.");
			}
			else setMSCN(mscn);
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;

		}
		
	} while (check==false);
}
void Setting::inputOdo()
{
	regex checkOdo("^(0|[1-9][0-9]*)$");
	string odo = "";
	bool check = true;
	do
	{
		check = true;
		cout << "Enter the ODO: ";
		getline(cin, odo);
		try
		{
			if (odo.empty() || !regex_match(odo, checkOdo))
			{
				check = false;
				throw runtime_error("Invalid value! Please enter the valid ODO.");
			}
			else {
				int ODO = stoi(odo);
				setOdo(ODO);
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;

		}
		
	} while (check == false);

}
void Setting::inputRemidService()
{
	regex checkRemind("^(0|[1-9][0-9]*)$");
	string remind = "";
	bool check = true;
	do
	{

		check = true;
		cout << "Enter the RemindService: ";
		getline(cin, remind);
		try
		{
			if (remind.empty() || !regex_match(remind, checkRemind))
			{
				check = false;
				throw runtime_error("Invalid value! Please enter the valid RemindService.");
			}
			else {
				int myRemind = stoi(remind);
				setRemindService(myRemind);
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;

		}
		
	} while (check == false);
}

void Setting::inputPersonalInformation()
{
	 inputOwnerName();
	 inputEmail();
	 inputMSCN();
	 inputOdo();
	 inputRemidService();
}
void Setting::exportPersonalInformation() {
	cout
		<< setw(20) << getOwnerName()
		<< setw(20) << getEmail()
		<< setw(20) << getMSCN()
		<< setw(20) << getOdo()
		<< setw(20) << getRemindService();
}

