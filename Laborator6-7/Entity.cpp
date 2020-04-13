#include "Entity.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
#include<sstream>

using namespace std;

Aplicatie::Aplicatie()
{
	this->name = NULL;
	this->consumMemorieKb = 0;
	this->status = NULL;
}

Aplicatie::Aplicatie(const char* name, int consumMemorieKb, const char* status)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->consumMemorieKb = consumMemorieKb;
	this->status = new char[strlen(status)+1];
	strcpy_s(this->status, 1 + strlen(status), status);
}

Aplicatie::Aplicatie(const Aplicatie& a)
{
	this->name = new char[strlen(a.name) + 1];
	strcpy_s(this->name, 1 + strlen(a.name), a.name);
	this->consumMemorieKb = a.consumMemorieKb;
	this->status = new char[strlen(a.status) + 1];
	strcpy_s(this->status, 1 + strlen(a.status),a.status);

}

Aplicatie::~Aplicatie()
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
	}
	consumMemorieKb = 0;
	if (this->status) 
	{
		delete[] this->status;
		this->status = NULL;
	}
}

char* Aplicatie::getName() {
	return this->name;
}

int Aplicatie::getConsumMemorieKb() {
	return this->consumMemorieKb;
}

char* Aplicatie::getStatus() {
	return this->status;
}


void Aplicatie::setName(const char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Aplicatie::setConsumMemorieKb(int consumMemorieKb)
{
	this->consumMemorieKb = consumMemorieKb;
}

void Aplicatie::setStatus(const char* status)
{
	if (this->status) {
		delete[] this->status;
	}
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

Aplicatie& Aplicatie::operator=(const Aplicatie& g) {
	this->setName(g.name);
	this->setConsumMemorieKb(g.consumMemorieKb);
	this->setStatus(g.status);
	return *this;
}

/*Aplicatie::Aplicatie(string linie)
{

	std::istringstream iss(linie);
	string tok1, tok2, tok3;
	iss >> tok1 >> tok2 >> tok3;
	name = new char[tok1.length() + 1];
	strcpy_s(name, tok1.length() + 1, tok1.c_str());
	consumMemorieKb = stoi(tok2);
	status = new char[tok3.length() + 1];
	strcpy_s(status, tok3.length() + 1, tok3.c_str());
}
*/
bool Aplicatie:: operator==(const Aplicatie& g) {
	return strcmp(this->name, g.name) == 0 && this->consumMemorieKb == g.consumMemorieKb && strcmp(this->name, g.name) == 0;
}

ostream& operator<<(ostream& os, const Aplicatie& g)
{
	os << g.name << " " << g.consumMemorieKb << " " << g.status ;
	return os;
}
