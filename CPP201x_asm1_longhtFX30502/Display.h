#pragma once
#include <iostream>
#include <regex>
#include <iomanip>
using namespace std;
class Display
{
	int lightLevel;
	int screenLightLevel;
	int taploLightLevel;
public:
	Display();
	~Display();

	// Hàm nhập thông tin Display
	void nhapThongTinDisplay();

	// Hàm xuất thông tin Display
	void xuatThongTinDisplay();

	// Các hàm set và get giá trị
	void setLightLevel(int lightLevel);
	int getLightLevel();
	void setScreenLightLevel(int screenLightLevel);
	int getScreenLightLevel();
	void setTaploLightLevel(int taploLightLevel);
	int getTaploLightLevel();
	
	// Nhập input cho các biến
	void inputLightLevel();
	void inputScreenLightLevel();
	void inputTaploLightLevel();
};

