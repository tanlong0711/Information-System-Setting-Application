#include <iostream>
#include <fstream>
#include <iomanip>
#include <regex>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <string>

#include "Car.h"
#include"Setting.h"
#include "Common.h"
#include "List.h"
#include"List.cpp"
using namespace std;

List<Setting*> arrCar;			  // Tạo mảng chứa các thông tin xe

vector <Common> listTimeZone; // Vector kieu Common để lưu list Timezones
vector <Common> listLanguage; // Vector kieu Common để lưu list Languages

// Mảng chứa các timezone để tạo file khi k có sẵn
string arrTimezone[32] = { "(GMT-12:00) /  International Date Line West","(GMT-11:00) /  Midway Island, Samoa",
		"(GMT-10:00) /  Hawaii", "(GMT-09:00) /  Alaska" ,"(GMT-08:00) /  Tijuana, Baja California" ,
		"(GMT-07:00) /  Chihuahua, La Paz, Mazatlan - New" ,"(GMT-06:00) /  Guadalajara, Mexico City, Monterrey - New" ,
		"(GMT-05:00) /  Eastern Time (US and Canada)" ,"(GMT-04:00) /  Atlantic Time (Canada)" ,
		"(GMT-03:30) /  Newfoundland" ,"(GMT-02:00) /  Mid-Atlantic" ,
		"(GMT-01:00) /  Azores" ,"(GMT-00:00) /  Monrovia, Reykjavik" ,"(GMT+01:00) /  Belgrade, Bratislava, Budapest, Ljubljana, Prague" ,
		"(GMT+02:00) /  Minsk" , "(GMT+03:00) /  Moscow, St. Petersburg, Volgograd" ,
		"(GMT+04:00) /  Abu Dhabi, Muscat" ,"(GMT+04:30) /  Kabul" ,"(GMT+05:00) /  Tashkent" ,
		"(GMT+05:30) /  Chennai, Kolkata, Mumbai, New Delhi" ,"(GMT+05:45) /  Kathmandu" ,
		"(GMT+06:00) /  Astana, Dhaka" ,"(GMT+06:30) /  Yangon (Rangoon) / " ,
		"(GMT+07:00) /  Bangkok, Hanoi, Jakarta" ,"(GMT+08:00) /  Beijing, Chongqing, Hong Kong, Urumqi" ,"(GMT+08:00) /  Irkutsk, Ulaanbaatar" ,
		"(GMT+09:00) /  Seoul" ,"(GMT+09:30) /  Adelaide" ,
		"(GMT+10:00) /  Canberra, Melbourne, Sydney" ,"(GMT+11:00) /  Magadan, Solomon Islands, New Caledonia" ,
		"(GMT+12:00) /  Fiji, Kamchatka, Marshall Is." ,"(GMT+13:00) /  Nuku'alofa" };	

// Mảng chứa các language để tạo file khi k có sẵn
string arrLanguage[30] = { "1 / Mandarin (entire branch)","2 / Spanish",
		"3 / English" ,"4 / Hindi" ,"5 / Arabic" ,"6 / Portuguese" ,
		"7 / Bengali" ,"8 / Russian" ,"9 / Japanese" ,"10 / Punjabi" ,
		"11 / German" ,"12 / Javanese" ,"13 / Wu (inc. Shanghainese)" ,"14 / Malay (inc. Indonesian and Malaysian)" ,
		"15 / Telugu" ,"16 / Vietnamese" ,"17 / Korean" ,"18 / French" ,
		"19 / Marathi" ,"20 / Tamil" ,"21 / Urdu" ,"22 / Turkish" ,
		"23 / Italian" ,"24 / Yue (inc. Cantonese)" ,"25 / Thai" ,"26 / Gujarati" ,
		"27 / Jin" ,"28 / Southern Min" ,"29 / Persian" ,"30 / Polish" };

// Tách chuỗi thành 2 phần từ ký tự n
const vector <string> formatString(const string& s,const char& n);

void createListTimezone(); // Tạo list TimeZones
void createListLanguage(); // Tạo list Languages
void downloadSetting();	   // Đọc lên file Setting từ file
void outputSetting();	   // Xuất thông tin cài đặt xuống file
void createLanguageFile(); // Tạo mới file language khi file không tồn tại sẵn
void createTimezoneFile(); // Tạo mới file timezone khi file không tồn tại sẵn

void menu(); // menu (MH1)
void subMenu();

void inputInformation(); // Hàm nhập thông tin (MH2)
void inputDisplaySetting(); // Hàm nhập vào chức năng Display setting
void inputSoundSetting(); // Hàm nhập vào chức năng Sound setting
void inputGeneralSetting(); // Hàm nhập vào chức năng General setting

void exportInformation();	// Hàm xuất thông tin (MH3)
void exportDisplaySetting();// Hàm xuất cài đặt Display
void exportSoundSetting();	// Hàm xuất cài đặt Sound
void exportGeneralSetting();// Hàm xuất cài đặt General
void exportAllSetting(int index);	// Hàm xuất tất cả setting
void displayByName();
void displayByMSCN();

void swapObj(int a, int b); // Đổi chỗ 2 Obj trong mảng arrCar
void bubbleSortObj();		// Sắp xếp Key number thứ tự tăng dần
int checkMSCN(string mscn);	// Hàm check sự trùng của MSCN
void sortLanguage(vector <Common> &listLanguage);		// Hàm sort list ngôn ngữ theo A-Z
int main()
{
	downloadSetting();
	createListTimezone();
	createListLanguage();
	menu();
	return 0;
}

void menu()
{
	int selection = 0;
	string inputString;
	cout << "---SELECT---" << endl;
	cout << "1. Input setting information" << endl;
	cout << "2. Print setting information" << endl;
	cout << "3. Exit" << endl;
	cout << "Your selection: ";
	do
	{
		regex selectNum("[1-3]{1}"); // Cho phép nhập từ số 1-3
		getline(cin, inputString);
		// Check giá trị nhập vào
		while (!regex_match(inputString,selectNum))
		{
			cout << "Please enter the number from 1-3!" << endl;
			cout << "Your select: ";
			getline(cin, inputString);
		}
		system("cls");
		// convert from string to interger
		selection = stoi(inputString);
		switch (selection)
		{
		case 1: 
			inputInformation();
			system("cls");
			break;
		case 2:
			exportInformation();
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "GoodBye!";
			exit(0); // kết thúc chương trình thành công
			break;
		default:
			cout << "Please enter the number from 1 -3!" << endl;
			cout << "Your selection: ";
			break;
		}
	} while (selection!=3);
}


// Hàm check sự trùng của MSCN
int checkMSCN(string mscn)
{
	for (int i = 0; i < arrCar.size(); i++)
	{
		if (arrCar.get(i)->getMSCN() == mscn)
		{
			return i;
		}
	}
	return -1;
}

// Hàm nhập thông tin (MH2)
void inputInformation() {
	int selection = 0;
	string inputString;
	cout << "---SELECT---" << endl;
	cout << "1. Display setting" << endl;
	cout << "2. Sound setting" << endl;
	cout << "3. General setting" << endl;
	cout << "0. Exit" << endl;
	cout << "Your selection: ";
	do
	{
		regex selectNum("[0-3]{1}"); // Cho phép nhập từ số 1-3
		getline(cin, inputString);
		while (!regex_match(inputString, selectNum))
		{
			cout << "Please enter the number from 0-3!" << endl;
			cout << "Your select: ";
			getline(cin, inputString);
		}
		system("cls");
		selection = stoi(inputString);
		switch (selection)
		{
		case 0:
			system("cls");
			menu();
			break;
		case 1:
			inputDisplaySetting();
			break;
		case 2:
			inputSoundSetting();
			break;
		case 3:	
			inputGeneralSetting();
			break;
		default:
			cout << "Please enter the number from 0 -3!" << endl;
			cout << "Your selection: ";
			break;
		}
	} while (selection!=0);
}

// Các hàm nhập từng chức năng riêng
void inputDisplaySetting() {
	string yesNo = "n";	
do
{
	system("cls");
	cout << " --- Input Display Information --- " << endl;
	Setting* myTempCar = new Setting; //Create a new instance of the Setting, user-input temporary car
	cout << "Car index: " << arrCar.size() + 1 << endl;
	// Nhập thông tin cá nhân của xe
	myTempCar->inputPersonalInformation();
	// kiểm tra xe đã tồn tại?
	int Carindex = checkMSCN(myTempCar->getMSCN());
	if (Carindex >= 0)
	{
		// Đã tồn tại
		cout << "   ->This car already exists, data will be overwritten." << endl;
		// Nhập thông tin độ sáng của xe
		myTempCar->getDisplay()->nhapThongTinDisplay();
		arrCar.get(Carindex)->convertInfor(myTempCar); // Ghi đè các thông tin cơ bản
		arrCar.get(Carindex)->converInforDisplay(myTempCar); // Ghi đè các thông tin Display
		outputSetting();
		delete myTempCar;
	}

	else {
		if (arrCar.size() < 100) {
			// Chưa tồn tại -> tạo mới
			cout << "   ->This is car, data will be appended to your list." << endl;
			// Nhập thông tin độ sáng của xe
			myTempCar->getDisplay()->nhapThongTinDisplay();
			arrCar.add(myTempCar);
			outputSetting();
			myTempCar = nullptr;
		}
		else {
			cout << "The system has reached limit.";
		}
	}
	
	regex checkYesNo("[YyNn]"); // Kiểm tra xem nhập vào Y or N , y or n
	bool check = true;
	do
	{
		check = true;
		cout << "Will you input for Car " << arrCar.size() + 1 << " (yes/no)?";
		cin >> yesNo;
		if (!regex_match(yesNo, checkYesNo))
		{
			check = false;
			cout << "Invalid value! Please enter the valid input"<<endl;
		}
	} while (check == false);
	cin.ignore(1);
} while (yesNo=="y" || yesNo == "Y");
system("cls");
menu();
}
void inputSoundSetting() // Hàm nhập vào chức năng Sound setting
{
	string yesNo = "n";

	do
	{
		system("cls");
		cout << " --- Input Sound Information --- " << endl;
		Setting* myTempCar = new Setting; // Tạo 1 đối tượng tạm thời để nhập input
		cout << "Car index: " << arrCar.size() + 1 << endl;

		// Nhập thông tin cá nhân và chức năng Sound
		myTempCar->inputPersonalInformation();

		// Check sự trùng MSCN của xe
		int Carindex = checkMSCN(myTempCar->getMSCN());

		if (Carindex >= 0)
		{
			// ghi đè xe cũ tại vị trí trùng Carindex
			cout << "   ->This car already exists, data will be overwritten." << endl;
			myTempCar->getSound()->nhapThongTinSound();
			arrCar.get(Carindex)->convertInfor(myTempCar);
			arrCar.get(Carindex)->converInforSound(myTempCar);
			outputSetting();
			delete myTempCar;
		}
		else
		{
			if (arrCar.size() < 100) {
				cout << "   ->This is car, data will be appended to your list." << endl;
				myTempCar->getSound()->nhapThongTinSound();
				arrCar.add(myTempCar);
				outputSetting();
				myTempCar = nullptr;
			}
			else {
				cout << "The system has reached limit.";
			}
		}
		regex checkYesNo("[YyNn]"); // Kiểm tra xem nhập vào Y or N , y or n
		bool check = true;
		do
		{
			check = true;
			cout << "Will you input for Car " << arrCar.size() + 1 << " (yes/no)?";
			cin >> yesNo;
			if (!regex_match(yesNo, checkYesNo))
			{
				check = false;
				cout << "Invalid value! Please enter the valid input" << endl;
			}
		} while (check == false);
		cin.ignore(1);
	} while (yesNo=="Y"||yesNo=="y");
	system("cls");
	menu();
}
void inputGeneralSetting() // Hàm nhập vào chức năng General setting
{
	string yesNo = "n";

	do
	{
		system("cls");
		cout << " --- Input General Information --- " << endl;
		Setting* myTempCar = new Setting; // Tạo 1 đối tượng tạm thời để nhập input
		cout << "Car index: " << arrCar.size() + 1 << endl;

		// Nhập thông tin cá nhân và chức năng Sound
		myTempCar->inputPersonalInformation();

		// Check sự trùng MSCN của xe
		int Carindex = checkMSCN(myTempCar->getMSCN());

		if (Carindex >= 0)
		{
			// ghi đè xe cũ tại vị trí trùng Carindex
			cout << "   ->This car already exists, data will be overwritten." << endl;
			myTempCar->getGeneral()->nhapThongTinGeneral();
			arrCar.get(Carindex)->convertInfor(myTempCar);
			arrCar.get(Carindex)->converInforGeneral(myTempCar);
			outputSetting();
			delete myTempCar;
		}
		else
		{
			if (arrCar.size() < 100) {
				cout << "   ->This is car, data will be appended to your list." << endl;
				myTempCar->getGeneral()->nhapThongTinGeneral();
				arrCar.add(myTempCar);
				outputSetting();
				myTempCar = nullptr;
			}
			else {
				cout << "The system has reached limit.";
			}
		}
		regex checkYesNo("[YyNn]"); // Kiểm tra xem nhập vào Y or N , y or n
		bool check = true;
		do
		{
			check = true;
			cout << "Will you input for Car " << arrCar.size() + 1 << " (yes/no)?";
			cin >> yesNo;
			if (!regex_match(yesNo, checkYesNo))
			{
				check = false;
				cout << "Invalid value! Please enter the valid input" << endl;
			}
		} while (check == false);
		cin.ignore(1);
	} while (yesNo == "Y" || yesNo == "y");
	system("cls");
	menu();
}

// Hàm xuất thông tin (MH3)
void exportInformation() {
	int selection = 0;
	string inputString;
	cout << "---SELECT---" << endl;
	cout << "1. Print Display setting information" << endl;
	cout << "2. Print Sound setting information" << endl;
	cout << "3. Print General setting information" << endl;
	cout << "4. Print All setting information" << endl;
	cout << "5. Exit" << endl;
	cout << "Your selection: ";
	do
	{
		regex selectNum("[1-5]{1}"); // Cho phép nhập từ số 1-3
		getline(cin, inputString);
		while (!regex_match(inputString, selectNum))
		{
			cout << "Please enter the number from 1-5!" << endl;
			cout << "Your select: ";
			getline(cin, inputString);
		}
		system("cls");
		selection = stoi(inputString);
		switch (selection)
		{
		case 1:
			exportDisplaySetting();
			break;
		case 2:
			exportSoundSetting();
			break;
		case 3:
			exportGeneralSetting();
			break;
		case 4:
			subMenu();
			break;
		case 5:
			system("cls");
			menu();
			break;
		default:
			cout << "Please enter the number from 1 -5!" << endl;
			cout << "Your selection: ";
			break;
		}
	} while (selection != 0);
}

// Hàm xuất cài đặt Display
void exportDisplaySetting() {
	cout << left
		<< setw(20) << "Owner name"
		<< setw(20) << "Email"
		<< setw(20) << "Key number"
		<< setw(20) << "ODO number"
		<< setw(20) << "Remind service(km)"
		<< setw(20) << "Light Level"
		<< setw(20) << "Screen Light Level"
		<< setw(20) << "Taplo Light Level" << endl;
	bubbleSortObj();
	for (int i = 0; i < arrCar.size(); i++)
	{
		arrCar.get(i)->exportPersonalInformation();
		arrCar.get(i)->getDisplay()->xuatThongTinDisplay();
		cout << endl;
	}
	cout << endl;
	cout << "=========================================================" << endl;
	exportInformation();
}

// Hàm xuất cài đặt Sound
void exportSoundSetting() {
	cout << left
		<< setw(20) << "Owner name"
		<< setw(20) << "Email"
		<< setw(20) << "Key number"
		<< setw(20) << "ODO number"
		<< setw(20) << "Remind service(km)"
		<< setw(20) << "Media Volume"
		<< setw(20) << "Call Volume"
		<< setw(25) << "Notification Volume" 
		<< setw(20) << "Navigation Volume" << endl;
	bubbleSortObj();
	for (int i = 0; i < arrCar.size(); i++)
	{
		arrCar.get(i)->exportPersonalInformation();
		arrCar.get(i)->getSound()->xuatThongTinSound();
		cout << endl;
	}
	cout << endl;
	cout << "=========================================================" << endl;
	exportInformation();
}

// Hàm xuất cài đặt General
void exportGeneralSetting() {
	cout << left
		<< setw(20) << "Owner name"
		<< setw(20) << "Email"
		<< setw(20) << "Key number"
		<< setw(20) << "ODO number"
		<< setw(20) << "Remind service(km)"
		<< setw(20) << "TimeZone"
		<< "Language" << endl;
	bubbleSortObj();
	for (int i = 0; i < arrCar.size(); i++)
	{
		arrCar.get(i)->exportPersonalInformation();
		arrCar.get(i)->getGeneral()->xuatThongTinGeneral();
		cout << endl;
	}
	cout << endl;
	cout << "=========================================================" << endl;
	exportInformation();
}

// Hàm xuất tất cả setting
void exportAllSetting(int index)
{
	cout << left
		<< setw(5) << index + 1
		<< setw(20) << "Owner name"
		<< setw(20) << "Email"
		<< setw(20) << "Key number"
		<< setw(20) << "ODO number"
		<< setw(20) << "Remind service(km)" << endl;
	cout << left
		<< setw(5)<<"";
		arrCar.get(index)->exportPersonalInformation();
		cout << endl;
		// Xuất Display setting
		cout << left
		<< setw(5) << "";
		cout << left << setw(15) << "Display: "
			<< setw(20) << "Light Level"
			<< setw(20) << "Screen Light Level"
			<< setw(20) << "Taplo Light Level" << endl;
		cout << left << setw(20) << " ";
		arrCar.get(index)->getDisplay()->xuatThongTinDisplay();
		cout << endl;
		// Xuất Sound Setting
		cout << left
			<< setw(5) << ""; cout << left << setw(15) << "Sound: "
			<< setw(20) << "Media Volume"
			<< setw(20) << "Call Volume"
			<< setw(25) << "Notification Volume"
			<< setw(20) << "Navigation Volume" << endl;
		cout << left << setw(20) << " ";
		arrCar.get(index)->getSound()->xuatThongTinSound();
		cout << endl;
		// Xuất General Setting
		cout << left
			<< setw(5) << ""; cout << left << setw(15) << "General: "
		<< setw(20) << "TimeZone"
		<< "Language" << endl;
		cout << left << setw(20) << " ";
		arrCar.get(index)->getGeneral()->xuatThongTinGeneral();

	cout << endl;
	cout << "=========================================================" << endl;
	//exportInformation();
}
void displayByName() {
	Setting* myTempCar = new Setting; // Tạo 1 đối tượng tạm thời để nhập input
	myTempCar->inputOwnerName();
	bool check = false;
	cout << "============================== All Setting ==============================\n" << endl;
	for (int i = 0; i < arrCar.size(); i++)
	{
		if (arrCar.get(i)->getOwnerName() == myTempCar->getOwnerName()) {
			exportAllSetting(i);
			check = true;
		}
	}
		if (!check) cout << "Car not found.\n";
	exportInformation();
}
void displayByMSCN() {
	Setting* myTempCar = new Setting; // Tạo 1 đối tượng tạm thời để nhập input
	myTempCar->inputMSCN();
	int carIndex = checkMSCN(myTempCar->getMSCN());
	while (!(carIndex >= 0))
	{
		cout << "Invalid MSCN. Please enter the MSCN" << endl;
		myTempCar->inputMSCN();
		int carIndex = checkMSCN(myTempCar->getMSCN());
	}
	cout << "============================== All Setting ==============================\n" << endl;
	exportAllSetting(carIndex);
	exportInformation();
}

// hàm tách chuỗi bởi ký tự n
const vector <string> formatString(const string& s,const char& n)
{
	string buff = "";
	vector<string> v;
	for (auto a : s) {
		if (a != n)
		{
			buff += a;
		}
		else if (a == n && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
	{
		v.push_back(buff);
	}
	return v;
}

// Hàm tạo danh sách timeZone từ file
void createListTimezone()
{
	fstream inputFile;
	inputFile.open("timezones.txt", ios::in); // mở file
	try
	{
		// Check mở file
		if (!inputFile.is_open()) {
			createTimezoneFile();
			throw runtime_error("Unable to open file!");
		}

		string line;
		while (getline(inputFile, line)) // Đọc từng dòng từ file vào biến line
		{
			vector <string> format = formatString(line, '/'); // Tách ra 2 chuỗi với ký tự /
			Common list;
			if (format.size() >= 2)
			{
				list.setNumber(format.at(0));
				list.setName(format.at(1));
			}
			listTimeZone.push_back(list); // thêm vào mỗi dòng line vào list 
		}
		inputFile.close();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}
// Hàm tạo danh sách ngôn ngữ từ file
void createListLanguage()
{
	fstream inputFile;
	inputFile.open("languages.txt", ios::in); // mở file
	try
	{
		// Check mở file
		if (!inputFile.is_open()) {
			createLanguageFile();
			throw runtime_error("Unable to open file!");
		}
		string line;
		while (getline(inputFile, line)) // Đọc từng dòng từ file vào biến line
		{
			vector <string> format = formatString(line, '/'); // Tách ra 2 chuỗi với ký tự /
			Common list;
			if (format.size() >= 2)
			{
				list.setNumber(format.at(0));
				list.setName(format.at(1));
			}
			listLanguage.push_back(list); // thêm vào mỗi dòng line vào list 
		}
		sortLanguage(listLanguage);
		inputFile.close();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	
}

void createLanguageFile() // Tạo mới file language khi file không tồn tại sẵn
{
	fstream file("languages.txt", ios::out);

	for (int i = 0; i <30; i++) {
		file<< arrLanguage[i] << endl;
	}
	file.close();
}
void createTimezoneFile() // Tạo mới file timezone khi file không tồn tại sẵn
{
	fstream file("timezones.txt", ios::out);

	for (int i = 0; i < 32; i++) {
		file << arrTimezone[i] << endl;
	}	
	file.close();
}

void downloadSetting()	   // Đọc lên file Setting từ file
{
	fstream file("Setting.txt", std::ios::in);
	string temp; // luu tru cac tieu de du lieu
	string name;
	string email;
	string keyNumber;
	string odo;
	string reminder;
	string timezone;
	string language;
	string callVolum;
	string mediaVolum;
	string navigationVolum;
	string notificationVolum;
	string lightLvl;
	string screenLvl;
	string taploLvl;
	if (!file.is_open()) {
		cerr << "Failed to open the file\n";
}
	while (getline(file,temp))
	{
		try{
			Setting* myTempCar = new Setting();
			// Doc vao thong tin chu xe
			stringstream ss(temp);
			getline(ss, temp, ':');
			getline(ss, name, ';');
			getline(ss, email, ';');
			getline(ss, keyNumber, ';');
			getline(ss, odo, ';');
			getline(ss, reminder, '/');
			// Doc vao General
			getline(ss, temp, ':');
			getline(ss, language, ';');
			getline(ss, timezone, '/');
			// Doc vao Sound
			getline(ss, temp, ':');
			getline(ss, callVolum, ';');
			getline(ss, mediaVolum, ';');
			getline(ss, navigationVolum, ';');
			getline(ss, notificationVolum, '/');
			// Doc vao Display
			getline(ss, temp, ':');
			getline(ss, lightLvl, ';');
			getline(ss, screenLvl, ';');
			getline(ss, taploLvl, '/');
			ss >> temp;  // doc toi cuoi dong

			// luu tru lieu vao doi tuong tam thoi
			myTempCar->setOwnerName(name);
			myTempCar->setEmail(email);
			myTempCar->setMSCN(keyNumber);
			myTempCar->setOdo(stoi(odo));
			myTempCar->setRemindService(stoi(reminder));

			myTempCar->getGeneral()->setTimeZone(timezone);
			myTempCar->getGeneral()->setLanguage(language);

			myTempCar->getSound()->setMediaVolumeLevel(stoi(mediaVolum));
			myTempCar->getSound()->setCallVolumeLevel(stoi(callVolum));
			myTempCar->getSound()->setNavigationVolumeLevel(stoi(navigationVolum));
			myTempCar->getSound()->setNotificationVolumeLevel(stoi(notificationVolum));

			myTempCar->getDisplay()->setLightLevel(stoi(lightLvl));
			myTempCar->getDisplay()->setScreenLightLevel(stoi(screenLvl));
			myTempCar->getDisplay()->setTaploLightLevel(stoi(taploLvl));
			arrCar.add(myTempCar);
		}
		catch (const exception& e) {
			cerr << "Failed to open the file.\n";
		}
	}
		file.close();
}
void outputSetting()	   // Xuất thông tin cài đặt xuống file
{
	fstream file("Setting.txt", ios::out);
	try
	{
		if (file.is_open()) {

			for (int i = 0; i < arrCar.size(); i++) {
				file << "Common:"
					<< arrCar.get(i)->getOwnerName() << ";"
					<< arrCar.get(i)->getEmail() << ";"
					<< arrCar.get(i)->getMSCN() << ";"
					<< arrCar.get(i)->getOdo() << ";"
					<< arrCar.get(i)->getRemindService() << "/"
					<< "General:"
					<< arrCar.get(i)->getGeneral()->getLanguage() << ";"
					<< arrCar.get(i)->getGeneral()->getTimeZone() << "/"
					<< "Sound:"
					<< arrCar.get(i)->getSound()->getCallVolumeLevel() << ";"
					<< arrCar.get(i)->getSound()->getMediaVolumeLevel() << ";"
					<< arrCar.get(i)->getSound()->getNavigationVolumeLevel() << ";"
					<< arrCar.get(i)->getSound()->getNotificationVolumeLevel() << "/ "
					<< "Display:"
					<< arrCar.get(i)->getDisplay()->getLightLevel() << ";"
					<< arrCar.get(i)->getDisplay()->getScreenLightLevel() << ";"
					<< arrCar.get(i)->getDisplay()->getTaploLightLevel() << endl;
			}
		}
		else throw string ("Failed to open the file.\n");
		file.close();
	}
	catch (string &e)
	{
		cout << e;
	}
}


void sortLanguage(vector <Common>& listLanguage)		// Hàm sort list ngôn ngữ theo A-Z
{
	for (int i = 0; i < 30 - 1; i++) {
		for (int j = 0; j < 30 - i - 1; j++) {
			if (listLanguage[j].getName() > listLanguage[i + 1].getName()) {
				swap(listLanguage[j], listLanguage[j + 1]);
			}
		}
	}
}

// Sắp xếp Key number thứ tự tăng dần
void bubbleSortObj() {
	for (int i = 0; i < arrCar.size() - 1; i++) {
		for (int j = 0; j < arrCar.size() - i - 1; j++) {
			if (arrCar.get(j)->getMSCN() > arrCar.get(j + 1)->getMSCN()) {
				arrCar.swapObj(j, j + 1);
			}
		}
	}
}

// Sắp xếp Name thứ tự tăng dần
void bubbleSortByName() {
	for (int i = 0; i < arrCar.size() - 1; i++) {
		for (int j = 0; j < arrCar.size() - i - 1; j++) {
			if (arrCar.get(j)->getOwnerName() > arrCar.get(j + 1)->getOwnerName()) {
				arrCar.swapObj(j, j + 1);
			}
		}
	}
}
void subMenu() {
	int selection = 0;
	string inputString;
	cout << "---SELECT---" << endl;
	cout << "1. Search by MSCN" << endl;
	cout << "2. Search by Name" << endl;
	cout << "3. Back" << endl;
	cout << "Your selection: ";
	do
	{
		regex selectNum("[1-3]{1}"); // Cho phép nhập từ số 1-3
		getline(cin, inputString);
		// Check giá trị nhập vào
		while (!regex_match(inputString, selectNum))
		{
			cout << "Please enter the number from 1-3!" << endl;
			cout << "Your select: ";
			getline(cin, inputString);
		}
		system("cls");
		// convert from string to interger
		selection = stoi(inputString);
		switch (selection)
		{
		case 1:
			system("cls");
			displayByMSCN();
			break;
		case 2:
			system("cls");
			displayByName();
			break;
		case 3:
			system("cls");
			menu();
			break;
		default:
			cout << "Please enter the number from 1 -3!" << endl;
			cout << "Your selection: ";
			break;
		}
	} while (selection != 3);
}