#include "Car.h"

Car::Car()
{
	 ownerName="";
	 MSCN="";
	 email="";
	 odo=0;
	 remindService=0;
}
Car::~Car(){}

void Car::setOwnerName(string ownerName)
{
	this->ownerName = ownerName;
}
string Car::getOwnerName()
{
	return this->ownerName;
}

void Car::setMSCN(string MSCN)
{
	this->MSCN = MSCN;
}
string Car::getMSCN()
{
	return this->MSCN;

}

void Car::setEmail(string email) {
	this->email = email;

}
string Car::getEmail()
{
	return this->email;

}

void Car::setOdo(int odo)
{
	this->odo = odo;

}
int Car::getOdo()
{
	return this->odo;

}

void Car::setRemindService(int remindService)
{
	this->remindService = remindService;

}
int Car::getRemindService()
{
	return this->remindService;

}