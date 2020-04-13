#include "User_Interface.h"
#include "RepoTests.h"
#include <iostream>
#include "Tests.h"
using namespace std;

int main() {
	
	teste();
	testAdd();
	testGetAll();
	testDelete();
	testUpdate();
	int k = 1;
	Service S;
	UserInterface UI;
	RepoFile R;
	R.loadFromFile("Aplicatii.txt");
	S.setRepo(R);
	cout << "Dati memoria ";
	int memory;
	cin >> memory;
	cout << endl;
	UI.printMenu();
	while (true)
	{
		int option = 0;
		cout << endl;
		cout << "Alegeti optiunea: ";
		cin >> option;
		if (option == 1)
		{
			UI.addInMemory(S,memory);
			UI.printMenu();
		}
		if (option == 4)
		{
			UI.getAll(S);
			UI.printMenu();
		}
		if (option == 2)
		{
			UI.updateAplicatie(S);
			UI.getAll(S);
			UI.printMenu();
		}
		if (option == 3)
		{
			UI.delAplicatie(S);
			UI.getAll(S);
			UI.printMenu();
		}
		if (option == 5)
			break;
	}
	return 0;
}
