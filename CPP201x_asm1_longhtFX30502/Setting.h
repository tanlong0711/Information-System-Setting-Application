#pragma once
#include "Car.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"
#include <regex>
class Setting : public Car
{
	Display *myDisplay;
	Sound *mySound;
	General *myGeneral;

public:
	Setting();
	~Setting();
	
	// Các hàm set và get giá trị obj
	Display* getDisplay(); // Hàm truy cập obj từ bên ngoài
	void setDisplay(Display* display); // Hàm để set obj
	Sound* getSound();
	void setSound(Sound* sound);
	General* getGeneral();
	void setGeneral(General* general);

	void inputPersonalInformation();	// Nhập thông tin cá nhân cho xe
	void exportPersonalInformation();	// Xuất thông tin cá nhân xe

	void convertInfor(Setting* set); // Chuyển đổi obj
	void converInforFull(Setting& set); // chuyển đổi full thông tin obj

	// Chuyển đổi thông tin Display
	void converInforDisplay(Setting* set);
	// Chuyển đổi thông tin Sound
	void converInforSound(Setting* set);
	// Chuyển đổi thông tin General
	void converInforGeneral(Setting* set);

	// Nhập input cho các biến cá nhân của xe
	void inputOwnerName();
	void inputEmail();
	void inputMSCN();
	void inputOdo();
	void inputRemidService();
};

