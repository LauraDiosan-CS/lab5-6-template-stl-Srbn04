#include "User_Interface.h"
#include <iostream>
using namespace std;

UserInterface::UserInterface()
{
	this->s;
}

void UserInterface::printMenu()
{
	cout << "1. Add " << endl;
	cout << "2. Update " << endl;
	cout << "3. Delete " << endl;
	cout << "4. Show files " << endl;
	cout << "5. Break " << endl;
}

void UserInterface::addInMemory(Service& s,int nr)
{
	char name[20];
	char status[10];
	int consumMemorieKb;
	int n = 0;
	cout << "Dati numele: ";
	cin >> name;
	cout << "Dati consumMemorieKb(!!!>0): ";
	cin >> consumMemorieKb;
	while (consumMemorieKb <= 0)
	{
		cout << "Consumul de memorie trebuie sa fie o valoare pozitiva ! " << endl;
		cout << "Dati consumul de memorie din nou ! ";
		cin >> consumMemorieKb;
	}
	cout << "Dati statusul(!!!ram/swap): ";
	cin >> status;
	while (strcmp(status, "swap") != 0 && strcmp(status, "ram") != 0)
	{
		cout << "Statusul trebuie sa fie ram sau swap " << endl;
		cout << "Dati statusul din nou ";
		cin >> status;
	}
	Aplicatie a(name, consumMemorieKb, status);
	s.addInMemory(a,nr);
	cout << endl;
}

void UserInterface::getAll(Service& s)
{
	map<int, Aplicatie> elements;
	elements=s.getAll();
	map<int, Aplicatie>::iterator it;
	cout<<"Toate aplicatiile sunt:  " << endl;
	for (it = elements.begin(); it != elements.end(); it++) {
		cout << it->first <<"-----"<< it->second;
		cout << endl;
	}
	cout << endl;
}

void UserInterface::delAplicatie(Service& s)
{
	cout << "Sterge aplicatia cu numarul: ";
	map<int, Aplicatie>elements;
	elements=s.getAll();
	int number; 
	cin >> number; 
	int n = s.getSize();
	int i = 0;
	map<int, Aplicatie>::iterator it;
	for (it = elements.begin(); it != elements.end(); it++) {
		if (it->first == number) {
			s.deleteElement(number);
			n--;
		}
	}
}

void UserInterface::updateAplicatie(Service& s)
{
	cout << "Update la exercitiul cu cheia: ";
	int nr; 
	cin >> nr;
	cout << "new name: "; 
	char  newName[10];
	cin >> newName;
	cout << "new consumMemorieKb: "; 
	int newConsumMemorieKb; 
	cin >> newConsumMemorieKb;
	while (newConsumMemorieKb <= 0)
	{
		cout << "Consumul de memorie trebuie sa fie o valoare pozitiva ! " << endl;
		cout << "Dati consumul de memorie din nou ! ";
		cin >> newConsumMemorieKb;
	}
	cout << "new status: ";
	char newStatus[10]; 
	cin >> newStatus;
	while (strcmp(newStatus, "swap") != 0 && strcmp(newStatus, "ram") != 0)
	{
		cout << "Statusul trebuie sa fie ram sau swap " << endl;
		cout << "Dati statusul din nou ";
		cin >> newStatus;
	}

	map<int, Aplicatie> elements;
	elements=s.getAll();
	Aplicatie a = elements .at(nr);
	s.updateAplicatie(a, nr, newName, newConsumMemorieKb, newStatus);
}

UserInterface::~UserInterface()
{
}
