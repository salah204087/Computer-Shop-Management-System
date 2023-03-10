#include "SignUp.h"
#include <string>
#include<iostream>
#include <algorithm>
#include <regex>
using namespace std;
SignUp::SignUp(list<string> name, list<string> password, list<string> phone, list<string> mail, list <string> usertype, list <double> money)
{
	this->mail = mail;
	this->name = name;
	this->password = password;
	this->phone = phone;
	this->usertype = usertype;
	this->money = money;
}

SignUp::SignUp()
{
}

SignUp::~SignUp()
{
}

void SignUp::GetName()
{
	string Name;
	regex regx("[@_!#$%^&*()<>?/|}{~:.]");
	cout << "Enter your name:";
	while (true)
	{
		getline(cin >> ws, Name);
		if (any_of(Name.begin(), Name.end(), ::isdigit) || regex_search(Name, regx) != 0)
		{
			cout << "Please enter valid name doesn't containing digits or symbols:";
		}
		else
			break;
	}
	for_each(Name.begin(), Name.end(), [](char& c) {
		c = ::tolower(c); });
	name.push_back(Name);
}

void SignUp::GetPass()
{
	string  pass = "";
	while(true)
	{	
		cout << "Enter your password(at least 8 character):";
		getline(cin >> ws, pass);
		if (pass.size() < 8)
		{
			cout << "please enter at least 8 character." << endl;
			continue;
		}
		else
			break;
	}
	password.push_back(pass);
}

void SignUp::GetPhone()
{
	string Phone;
	regex regx("[@_!#$%^&*()<>?/|}{~:.]");
	cout << "Enter your phone number:";
	while (true)
	{
		getline(cin >> ws, Phone);
		string first_three = Phone.substr(0, 3);
		if (isWhitespace(Phone) != 0
			|| (first_three != "010"
				&& first_three != "011"
				&& first_three != "012"
				&& first_three != "015")
			|| Phone.size() != 11
			|| any_of(Phone.begin(), Phone.end(), ::isalpha)
			|| regex_search(Phone, regx) != 0)
			cout << "Please enter valid phone number:";
		else
			break;
	}
	phone.push_back(Phone);
}

void SignUp::GetMail()
{
	string Mail;
	regex regx("[!#$%^&*()<>?/|}{~:]");
	cout << "Enter your e_mail:";
	while (true)
	{
		string check = "not found";
		getline(cin >> ws, Mail);
		if (Mail.find("@") != std::string::npos
			&& Mail.find(".") != std::string::npos) {
			check = "found";
		}
		else
			check = "not found";
		if (regex_search(Mail, regx) != 0
			|| isWhitespace(Mail) != 0
			|| check == "not found")
			cout << "Please enter valid mail it doesn't contain this symbols([!#$%^&*()<>?/|}{~:],white space and must containing (@) and (.):";
		else
			break;
	}
	mail.push_back(Mail);
}
int SignUp::isWhitespace(string& str)
{
	int count = 0;
	int length = str.length();
	for (int i = 0; i < length; i++) {
		int c = str[i];
		if (isspace(c))
			count++;
	}
	return count;
}

void SignUp::GetMoney()
{
	double Money;
	while(true)
	{
		cout << "Enter how much money you have in the bank to buy:";
		cin >> Money;
		if (Money < 0)
			cout << "please enter valid value." << endl;
		else
			break;
	}
	money.push_back(Money);

}

void SignUp::sign()
{
	
	int choice;
	while (true)
	{
		cout << "1-sign up as user\n" << "2-sign up as admin\n" <<"3-Exit\n" << "Enter the number of the choice:";
		cin >> choice;
		if (choice == 1)
		{
			usertype.push_back("user");
			GetName();
			GetMail();
			GetPass();
			GetPhone();
			GetMoney();
			cout << "signed up successfully" << endl;
			break;
		}
		else if (choice == 2)
		{
			while (true)
			{
				string checkadmin;
				string checkpass;
				cout << "***************************		<Log in as adminstrator to add admin's>		*****************************" << endl;
				cout << "enter the name of adminstrator:";
				cin >> checkadmin;
				cout << "enter the password of adminstrator:";
				cin >> checkpass;
				if (admin == checkadmin && AdminPass == checkpass)
				{
					cout << "logged in as adminstrator successfully" << endl;
					cout << "***************************		<add admin>		*****************************" << endl;
					usertype.push_back("admin");
					GetName();
					GetMail();
					GetPass();
					GetPhone();
					cout << "signed up successfully" << endl;
					break;
				}
				else
				{
					cout << "the name or password is wrong,please enter valid data." << endl;
				}
			}
			break;
		}
		else if (choice == 3)
			break;
	}
}

tuple<string,string> SignUp::LogInUser()
{
	int check = 0;
	for (auto it = usertype.begin(); it != usertype.end(); ++it) {
		if (*it == "user") {
			check++;
			break;
		}
	}
	if (check!=0)
	{
		string CheckMail;
		string CheckPass;
		int index = 0;
		while (true)
		{
			cout << "Enter your E_Mail:";
			getline(cin >> ws, CheckMail);
			cout << "Enter your password:";
			getline(cin >> ws, CheckPass);
			for (auto it = mail.begin(); it != mail.end(); ++it) {
				if (*it == CheckMail) {
					break;
				}
				index++;
			}
			auto it = password.begin();
			advance(it, index);
			if (CheckPass == *it)
			{
				cout << "logged in successfully" << endl;
				break;
			}
			else
				cout << "Your email or password is wrong" << endl;
		}
		auto n = name.begin();
		advance(n, index);
		auto ph = phone.begin();
		advance(ph, index);
		return make_tuple(*n, *ph);
	}
	else
	{
		cout << "the database is empty pls sign up" << endl;
		sign();
		cout << "***************************		<Log in as user>		*****************************" << endl;
		return LogInUser();
	}
}

void SignUp::LogInAdmin()
{
	int check = 0;
	for (auto it = usertype.begin(); it != usertype.end(); ++it) {
		if (*it == "admin") {
			check++;
			break;
		}
	}
	if (check!=0)
	{
		string CheckMail;
		string CheckPass;
		int index = 0;
		while (true)
		{
			cout << "Enter your E_Mail:";
			getline(cin >> ws, CheckMail);
			cout << "Enter your password:";
			getline(cin >> ws, CheckPass);
			for (auto it = mail.begin(); it != mail.end(); ++it) {
				if (*it == CheckMail) {
					break;
				}
				index++;
			}
			auto it = password.begin();
			advance(it, index);
			auto ty = usertype.begin();
			advance(ty, index);
			if (CheckPass == *it && *ty == "admin")
			{
				cout << "logged in successfully" << endl;
				break;
			}
			else
				cout << "Your email or password is wrong" << endl;
		}
	}
	else
	{
		cout << "You didn't added any admin's\n" << "1-add admin\n" << "2-Log in as adminstrator\n"<< "Enter your choice:";
		int choice;
		string n, p;
		cin >> choice;
		if (choice == 1)
		{
			sign();
			cout << "***************************		<Log in as admin>		*****************************" << endl;
			LogInAdmin();
		}
		else if (choice == 2)
		{
			while(true)
			{
				cout << "Enter adminstrator's name:";
				getline(cin >> ws, n);
				cout << "Enter adminstrator's password:";
				getline(cin >> ws, p);
				if (n == admin && p == AdminPass)
				{
					cout << "Logged in successfully" << endl;
					break;
				}
				else
					cout << "the name or password of adminstrator is wrong" << endl;
			}

		}
	}
}
void SignUp::DisplayAllUsers()
{
	auto N = name.begin();
	auto E = mail.begin();
	auto P = phone.begin();
	while (!name.empty()) {
		cout <<"Name:" << *N << endl;
		cout <<"E-Mail:" << *E << endl;
		cout <<"Phone:" << *P << endl;
		cout << "				*********************************************				" << endl;
		++N;
		++E;
		++P;
		if (N == name.end())
			break;

	}
}

void SignUp::AddMoney(string auth)
{
	int index = 0;
	double addmoney=0;
	for (auto it = name.begin(); it != name.end(); ++it) {
		if (*it == auth) {
			break;
		}
		index++;
	}
	auto add = money.begin();
	advance(add, index);
	while (true)
	{
		cout << "how much you want to add:";
		cin >> addmoney;
		if (addmoney <= 0)
			cout << "please enter valid value(not negative or nothing)" << endl;
		else
			break;
	}
	cout << "the money added to your account" << endl;
}
