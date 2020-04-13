#pragma once
#include <ostream>
using namespace std;

class Aplicatie {
private:
	char* name;
	int consumMemorieKb;
	char* status;
public:
	Aplicatie();
	Aplicatie(const char* name, int consumMemorieKb, const char* status);
	Aplicatie(const Aplicatie& g);
	~Aplicatie();
	char* getName();
	int getConsumMemorieKb();
	//Aplicatie(string linie);
	char* getStatus();
	void setName(const char* name);
	void setConsumMemorieKb(int consumMemorieKb);
	void setStatus(const char* status);
	Aplicatie& operator=(const Aplicatie& g);
	bool operator==(const Aplicatie& g);
	friend ostream& operator<<(ostream& os, const Aplicatie& g);
};

