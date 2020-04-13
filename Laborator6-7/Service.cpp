#include "Service.h"
#include <iostream>
using namespace std;

int aux;

Service::Service()
{
}

Service::Service(const RepoFile& r)
{
	repo = r;
}

void Service::setRepo(const RepoFile& r)
{
	repo = r;
}

void Service::addElement(Aplicatie& a)
{
	map<int, Aplicatie> elements;
	elements = repo.getAll();
	map<int, Aplicatie>::iterator it;
	int ok = 1;
	for (it = elements.begin(); it != elements.end(); it++) {
		if (strcmp(it->second.getName(), a.getName())==0 ){
			ok =0 ;
			cout << endl << "Overwrote" << endl;
		}
	}
	if (ok) {
		repo.addElem(a);
		repo.saveToFile();
	}
}

void Service::updateAplicatie(Aplicatie& a, int position, char* name, int consumMemorieKb, char* status)
{
	repo.updateElem(a, position, name, consumMemorieKb, status);
	repo.saveToFile();
}


void Service::deleteElement(int position)
{
	repo.deleteElem(position);
	repo.saveToFile();
}

map<int, Aplicatie> Service::getAll() {
	return repo.getAll();
}


int Service::getSize()
{
	return repo.getSize();
}

Service::~Service()
{
	map<int, Aplicatie>elements;
	elements.clear();
}

void Service::addInMemory(Aplicatie& a, int nr)
{
	cout << endl;
	int aux = nr;
	map < int, Aplicatie>elements;
	elements = repo.getAll();
	map<int, Aplicatie>::iterator it;
	if (a.getConsumMemorieKb() > aux)
		cout << "Imposibil ";
	//acum calculam memoria ramasa ce poate fi utilizata
	for (it = elements.begin(); it != elements.end(); it++)
		if (strcmp(it->second.getStatus(), "ram") == 0)
			nr = nr - it->second.getConsumMemorieKb();
	if (a.getConsumMemorieKb() < nr)
	{
		repo.addElem(a);
		repo.saveToFile();
	}
	else
		if (a.getConsumMemorieKb() < aux && a.getConsumMemorieKb() >= nr) // daca e mai mare decat ce a ramas dar mai mica decat totalul
		{
			int i = 0;
			for (it = elements.begin(); it != elements.end(); it++ , i++)
				while (a.getConsumMemorieKb() > nr)
					if (strcmp(it->second.getStatus(), "ram") == 0)
					{
						it->second.setStatus("swap"); // mutam in swap
						repo.updateElem(it->second, i, (char*)it->second.getName(), it->second.getConsumMemorieKb(), (char*)"swap");
						nr += it->second.getConsumMemorieKb(); // eliberam memoria din ram ce a fost mutata in swap
					}
			{
				repo.addElem(a);
				repo.saveToFile();
			}

		}

}