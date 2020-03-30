#include "Entity.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Aplicatie::Aplicatie()
{
	this->name = NULL;
	this->consumMemorieKb = 0;
	this->status = NULL;
}

Aplicatie::Aplicatie(char* name, int consumMemorieKb, char* status)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->consumMemorieKb = consumMemorieKb;
	this->status = new char[strlen(status)+1];
	strcpy_s(this->status, 1 + strlen(status), status);
}

Aplicatie::Aplicatie(const Aplicatie& g)
{
	this->name = new char[strlen(g.name) + 1];
	strcpy_s(this->name, 1 + strlen(g.name), g.name);
	this->consumMemorieKb = consumMemorieKb;
	this->status = new char[strlen(g.status) + 1];
	strcpy_s(this->status, 1 + strlen(g.status),g.status);

}

Aplicatie::~Aplicatie()
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
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


void Aplicatie::setName(char* name)
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

void Aplicatie::setStatus(char* status)
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

bool Aplicatie:: operator==(const Aplicatie& g) {
	return strcmp(this->name, g.name) == 0 && this->consumMemorieKb == g.consumMemorieKb && strcmp(this->name, g.name) == 0;
}

ostream& operator<<(ostream& os, const Aplicatie& g)
{
	os << g.name << " " << g.consumMemorieKb << " " << g.status ;
	return os;
}
