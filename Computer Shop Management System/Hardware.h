#pragma once
using namespace std;
#include<string>
#include <list>
class Hardware
{
private:
	list <string> category;
public:
	Hardware(list<string> category);
	Hardware();
	~Hardware();
	void AddHardwareCategory();
	void GetHardCategory();
};

