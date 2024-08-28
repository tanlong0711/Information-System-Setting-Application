#include "Common.h"

Common::Common()
{
	number = "";
	name = "";
}
Common::~Common(){}

void Common::setNumber(string data)
{
	this->number = data;
}
string Common::getNumber()
{
	return this->number;
}

void Common::setName(string data) {
	this->name = data;

}
string Common::getName() {
	return this->name;
}
