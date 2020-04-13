
#include "RepoTests.h"
#include "RepoF.h"
#include<assert.h>
#include<iostream>

void testAdd() {
	RepoFile  r;
	r.loadFromFile("Teste.txt");
	r.clearFile();
	assert(r.getSize() == 0);
	Aplicatie a("Facebook", 250, "ram");
	r.addElem(a);
	assert(r.getSize() == 1);
	r.clearFile();
}

void testGetAll() {

	RepoFile r("Teste.txt");
	assert(r.getSize() == 0);
	map<int, Aplicatie> elements;
	Aplicatie a1("Facebook", 250, "ram");
	Aplicatie a2("Instagram",150, "ram");
	r.addElem(a1);
	r.addElem(a2);
	elements = r.getAll();
	assert(r.getSize() == 2);
	r.clearFile();
}
void testDelete() {

	RepoFile r("Teste.txt");
	assert(r.getSize() == 0);
	Aplicatie a1("Facebook", 250, "ram");
	Aplicatie a2("Instagram", 150, "ram");
	r.addElem(a1);
	r.addElem(a2);
	assert(r.getSize() == 2);
	r.deleteElem(1);
	assert(r.getSize() == 1);
	r.clearFile();

}

void testUpdate() {

	RepoFile r("Teste.txt");
	map<int, Aplicatie> elements;
	assert(r.getSize() == 0);
	Aplicatie a1("Facebook", 250, "ram");
	Aplicatie a2("Instagram", 150, "ram");
	r.addElem(a1);
	r.addElem(a2);
	Aplicatie a((char*)"Snapchat", 125, (char*)"swap");
	r.updateElem(a,0, (char*)"Snapchat", 2000, (char*)"swap");
	elements = r.getAll();
	map<int, Aplicatie> ::iterator itr = elements.find(0);
	assert(strcmp((itr->second).getName(), "Snapchat") == 0);
	r.clearFile();

}