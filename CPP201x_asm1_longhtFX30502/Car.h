#pragma once
#include <iostream>
#include <string>
using namespace std;

class Car
{
	string ownerName;
	string MSCN;
	string email;
	int odo;
	int remindService;

public:
	Car();
	~Car();

	void setOwnerName(string ownerName);
	string getOwnerName();

	void setMSCN(string MSCN);
	string getMSCN();

	void setEmail(string email);
	string getEmail();

	void setOdo(int odo);
	int getOdo();

	void setRemindService(int remidService);
	int getRemindService();
};

