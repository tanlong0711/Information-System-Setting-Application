#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

using namespace std;
class Sound
{
	int mediaVolumeLevel;
	int callVolumeLevel;
	int notificationVolumeLevel;
	int navigationVolumeLevel;
public:
	Sound();
	~Sound();

	void setMediaVolumeLevel(int level);
	int getMediaVolumeLevel();

	void setCallVolumeLevel(int level);
	int getCallVolumeLevel();

	void setNotificationVolumeLevel(int level);
	int getNotificationVolumeLevel();

	void setNavigationVolumeLevel(int level);
	int getNavigationVolumeLevel();

	// Nhập vào input các biến
	void inputMediaVolumeLevel();
	void inputCallVolumeLevel();
	void inputNotificationVolumeLevel();
	void inputNavigationVolumeLevel();

	// Nhâp vào thông tin Sound
	void nhapThongTinSound();

	// Xuất thông tin Sound
	void xuatThongTinSound();
};

