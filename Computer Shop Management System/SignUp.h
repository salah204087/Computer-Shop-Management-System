#pragma once
#include <iostream>
#include <list>
#include<tuple>
using namespace std;
class SignUp
{
private:
	
	string admin = "admin";
	string AdminPass = "admin1234";
protected:
	list <double> money;
	list <string> name;
	list <string> mail;
	list <string> password;
	list <string> phone;
	list <string> usertype;
public:
	SignUp(list <string> name,list <string> password,list <string> phone,list <string> mail, list <string> usertype, list <double> money);
	SignUp();
	~SignUp();
	void GetName();
	void GetPass();
	void GetPhone();
	void GetMail();
	void GetMoney();
	int isWhitespace(string& str);
	void sign();
	tuple<string,string> LogInUser();
	void LogInAdmin();
	void DisplayAllUsers();
	void AddMoney(string name);
};

