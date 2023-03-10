#include "Software.h"
#include <iostream>
#include <string>
using namespace std;

Software::Software(list<string> category)
{
	this->category = category;
}

Software::Software()
{
	category = { "no category" };
}

Software::~Software()
{
}

void Software::AddSoftwareCategory()
{
	string choice;
	cout << "1-Games\n" << "2-Progarms\n" << "3-Driver software\n" << "4-Operating system"<<endl;
	while(true)
	{
		cout << "input your choice:";
		getline(cin >> ws, choice);
		if (choice == "1" || choice == "Games" || choice == "games")
		{
			category.push_back("Games");
			break;
		}
		else if (choice == "2" || choice == "Programs" || choice == "programs")
		{
			category.push_back("Programs");
			break;
		}
		else if (choice == "3" || choice == "Driver software" || choice == "driver software")
		{
			category.push_back("Driver software");
			break;
		}
		else if (choice == "4" || choice == "Operating system" || choice == "operating system")
		{
			category.push_back("Operating system");
			break;
		}
		else
			cout << "you entered unvalid choice,please enter valied choice" << endl;
	}

}
void Software::GetSoftCategory()
{
	for (auto i : category)
		cout << "Category:" << i << endl;
}
