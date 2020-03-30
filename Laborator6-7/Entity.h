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
	Aplicatie(char* name, int consumMemorieKb, char* status);
	Aplicatie(const Aplicatie& g);
	~Aplicatie();
	char* getName();
	int getConsumMemorieKb();
	char* getStatus();
	void setName(char* name);
	void setConsumMemorieKb(int consumMemorieKb);
	void setStatus(char* status);
	Aplicatie& operator=(const Aplicatie& g);
	bool operator==(const Aplicatie& g);
	friend ostream& operator<<(ostream& os, const Aplicatie& g);
};

