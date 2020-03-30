#include<iostream>
#include"Tests.h"
#include "Entity.h"
#include<assert.h>
#include<string.h>
using namespace std;

void teste()
{
	Aplicatie f((char*)"League", 1500, (char*)"ram");
	f.setName((char*)"Legends");
	assert(strcmp(f.getName() ,(char*)"Legends")==0);
	f.setConsumMemorieKb(2500);
	assert(f.getConsumMemorieKb() == 2500);
	f.setStatus((char*)"swap");
	assert(strcmp(f.getStatus(), (char*)"swap") == 0);

	Aplicatie g = f;
	Aplicatie h;
	h = f;
	assert(h == f);
	cout << "Tests done ! ";
}