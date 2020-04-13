#pragma once
#include "Entity.h"
#include <map>
using namespace std;

class RepoFile
{
private:
	map<int, Aplicatie> elements;
	int nr;
	const char* fisier;
public:
	RepoFile();
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void saveToFile();
	void clearFile();
	void addElem(Aplicatie);
	void updateElem(Aplicatie& a, int pos, char* name, int consumMemorieKb, char* status);
	void deleteElem(int position);
	map<int, Aplicatie> getAll();
	int getSize();
	~RepoFile();
};	