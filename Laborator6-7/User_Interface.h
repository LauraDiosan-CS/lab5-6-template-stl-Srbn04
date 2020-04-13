#pragma once
#include "Entity.h"
#include "RepoFile.h"
#include "Service.h"

class UserInterface {
private:
	Service s;
public:
	UserInterface();
	~UserInterface();
	void printMenu();
	void addInMemory(Service& s,int);
	void getAll(Service& s);
	void delAplicatie(Service& s);
	void updateAplicatie(Service& s);
};