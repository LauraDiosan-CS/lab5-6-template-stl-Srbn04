#pragma once
#include "Entity.h"
#include "RepoF.h"
#include <map>

class Service {
private:
	RepoFile repo;
public:
	Service();
	Service(const RepoFile&);
	~Service();
	void setRepo(const RepoFile&);
	void addElement(Aplicatie& );
	void updateAplicatie(Aplicatie& , int , char* , int , char* );
	void deleteElement(int);
	map<int, Aplicatie> getAll();
	int getSize();
	void addInMemory(Aplicatie&,int);
};