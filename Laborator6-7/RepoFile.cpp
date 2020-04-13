#include "RepoF.h"
#include <fstream>
#include <string>
using namespace std;

RepoFile::RepoFile() {
	this->elements;
	this->nr = 0;
}

RepoFile::RepoFile(const char* fileName)
{
	fisier = fileName;
	ifstream f(fileName);
	string linie;
	char* name = new char[30];
	int consumMemorieKb=0;
	char* status = new char[30];
	while (f>>name>>consumMemorieKb>>status) {
		f >> name >> consumMemorieKb >> status;
		if (strcmp(name, "") != 0) {
			Aplicatie a(name, consumMemorieKb, status);
			addElem(a);
		}
	}
	delete[] name; 
	delete[] status;
	f.close();
}



void RepoFile::loadFromFile(const char* fileName)
{
	elements.clear();
	fisier = fileName;
	ifstream f(fileName);
	char* name = new char[10];
	int consumMemorieKb=0;
	char* status = new char[10];
	while (f>>name>>consumMemorieKb>>status) {
		f >> name >> consumMemorieKb >> status;
		if (strcmp(name, "") != 0) {
			Aplicatie a(name, consumMemorieKb, status);
			addElem(a);
		}
	}
	delete[] name; 
	delete[] status;
	f.close();
}

void RepoFile::saveToFile()
{
	ofstream f(fisier);
	map<int, Aplicatie>::iterator it;
	for (it = elements.begin(); it != elements.end(); it++) {
		f << it->second.getName() << " " << it->second.getConsumMemorieKb() << " " << it->second.getStatus() << endl;
	}
	f.close();
}

void RepoFile::addElem(Aplicatie a)
{
	elements.insert(pair<int, Aplicatie>(nr++, a));
}


void RepoFile::updateElem(Aplicatie& a, int position, char* newName, int newConsumMemorieKb, char* newStatus)
{
	a.setName(newName);
	a.setConsumMemorieKb(newConsumMemorieKb);
	a.setStatus(newStatus);
	elements[position] = a;
}

void RepoFile::deleteElem(int position)
{
	elements.erase(position);
}

map<int, Aplicatie> RepoFile::getAll() {
	return elements;
}

int RepoFile::getSize()
{
	return elements.size();
}

RepoFile::~RepoFile()
{
}
void RepoFile::clearFile() {

	std::ifstream File;
	std::string filepath = "Teste.txt";
	File.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc);
	if (!File.is_open() || File.fail())
	{
		File.close();
		printf("\nError : failed to erase file content !");
	}
	File.close();
}
