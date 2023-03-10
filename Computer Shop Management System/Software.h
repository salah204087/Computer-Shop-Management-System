#pragma once
#include <string>
#include <list>
using namespace std;
class Software
{
private:
	list <string> category;
public:
	Software(list<string> category);
	Software();
	~Software();
	void AddSoftwareCategory();
	void GetSoftCategory();
};

