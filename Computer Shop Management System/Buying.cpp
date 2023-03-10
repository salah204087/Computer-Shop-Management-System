#include "Buying.h"
#include <iostream>
#include <string>
using namespace std;
Buying::Buying(list <string> report, list<string> LocationOrder, list <string> reservation)
{
	this->report = report;
	this->LocationOrder = LocationOrder;
	this->reservation = reservation;
}

Buying::Buying()
{

}

Buying::~Buying()
{
}
void Buying::BuyingProcess(string n, string p)
{
	int choice;
	int index_product = 0;
	int index_user = 0;
	int check_prodect = -1;
	while (true)
	{
		cout << "1-show all products\n" << "2-show software products\n" << "3-show hardware products\n" << "4-searching\n" << "5-Exit\n";
		cout << "Enter your choice:";
		cin >> choice;
		if (choice == 1)
		{
			if (!NameProduct.empty())
			{
				DispalyAllProduct();
				BuyingSteps(n, p);
				
			}
			else
				cout << "There are no products" << endl;
		}
		else if (choice == 2)
		{
			int check = 0;
			for (auto it = type.begin(); it != type.end(); ++it) {
				if (*it == "Software") {
					check++;
					break;
				}
			}
			if (check != 0)
			{
				GetSoftProduct();
				BuyingSteps(n,p);
			}
			else
				cout << "There are no software products" << endl;
		}
		else if (choice == 3)
		{
			int check = 0;
			for (auto it = type.begin(); it != type.end(); ++it) {
				if (*it == "Hardware") {
					check++;
					break;
				}
			}
			if (check != 0)
			{
				GetHardProduct();
				BuyingSteps(n,p);
			}
			else
			cout << "There are no hardware products" << endl;
		}
		else if (choice == 4)
		{
			if (!NameProduct.empty())
			{
				BuyingSteps(n, p);
			}
			else
				cout << "No products addded(The DataBase is empty)." << endl;
		}
		else
			break;
	}

}
void Buying::DisplayReports()
{
	for (auto i : report)
		cout << i << endl;
}

void Buying::DisplayLocationOrders()
{
	for (auto i : LocationOrder)
		cout << i << endl;
}

void Buying::DisplayReservation()
{
	for (auto i : reservation)
		cout << i << endl;
}

void Buying::BuyingSteps(string n, string p)
{
	int choice;
	int index_product = 0;
	int index_user = 0;
	int check_prodect = -1;
	while (true)
	{
		string productname = "";
		cout << "Enter name of product you want to buy:";
		getline(cin >> ws, productname);
		for (auto it = NameProduct.begin(); it != NameProduct.end(); ++it) {
			if (*it == productname) {
				check_prodect++;
				break;
			}
			index_product++;
		}
		if (check_prodect == -1)
		{
			index_product = 0;
			cout << "you entered unvalid name" << endl;
		}
		else
			break;
	}
	int choicebuying;
	auto Name = NameProduct.begin();
	advance(Name, index_product);
	auto Price = PriceProduct.begin();
	advance(Price, index_product);
	auto Quantity = QuantityProduct.begin();
	advance(Quantity, index_product);
	auto Details = DetailsProduct.begin();
	advance(Details, index_product);
	cout << "Name:" << *Name << "\nPrice" << *Price << "\nQuantity:" << *Quantity << "\nDetails" << *Details << endl;
	cout << "1-Buy the product and delivered to you\n" << "2-Product reservation\n" << "3-Exit" << endl;
	cout << "Enter your choice:";
	cin >> choicebuying;
	if (choicebuying == 1)
	{

		while (true)
		{
			int index = 0;
			int check_user = -1;
			for (auto it = name.begin(); it != name.end(); ++it) {
				if (*it == n) {
					check_user++;
					break;
				}
				index++;
				index_user = index;
			}
			if (check_user == -1)
				cout << "you entered unvalid name" << endl;
			else
			{
				break;
			}
		}
		int productwant;
		auto usermoney = money.begin();
		advance(usermoney, index_user);
		while (true)
		{
			if (*Quantity != 0)
			{
				cout << "How much of this product do you want?";
				cin >> productwant;
				if (productwant > *Quantity)
				{
					int quantitychoice = 0;
					cout << "sorry we dont have the quantity you want,pls enter valid quantity." << endl;
					cout << "1-change the quantity you want\n" << "2-Exit\n" << "Enter your choice:";
					cin >> quantitychoice;
					if (quantitychoice == 1)
						continue;
					else
						break;
				}
				else if (productwant < 1)
					cout << "please enter valid qunatity,you enterd 0 or negative value." << endl;
				else
				{
					if (productwant * (*Price) <= *usermoney)
					{
						string location;
						int decision;
						*usermoney -= productwant * (*Price);
						*Quantity -= productwant;
						cout << "The purchase was completed successfully" << endl;
						cout << "Please enter the location from which you want to receive the product:";
						getline(cin >> ws, location);
						LocationOrder.push_back(location);
						cout << "Do you want make report about product or service\n" << "1-yes\n" << "2-no\n" << "please enter your choice:";
						cin >> decision;
						if (decision == 1)
						{
							string Report;
							cout << "enter your report:";
							getline(cin >> ws, Report);
							report.push_back(n + " " + p + "\n" + Report);
							break;
						}
						else
							break;
					}
					else
					{
						int choice;
						cout << "Your money does not cover the cost." << endl;
						cout << "Do you want to reduce the quantity\n" << "1-yes\n" << "2-Exit\n" << "enter your choice:";
						cin >> choice;
						if (choice == 1)
							continue;
						else
							break;
					}
				}
			}
			else
			{
				cout << "The quantity of this product is over" << endl;
				break;
			}
		}


	}
	else if (choicebuying == 2)
	{
		int check_user = -1;
		while (true)
		{
			for (auto it = name.begin(); it != name.end(); ++it) {
				if (*it == n) {
					check_user++;
					break;
				}
				index_user++;
			}
			if (check_user == -1)
				cout << "you entered unvalid name" << endl;
			else
				break;
		}
		int productwant;
		auto usermoney = money.begin();
		advance(usermoney, index_user);
		while (true)
		{
			if (*Quantity != 0)
			{
				cout << "How much of this product do you want?";
				cin >> productwant;
				if (productwant > *Quantity)
				{
					int quantitychoice = 0;
					cout << "sorry we dont have the quantity you want,pls enter valid quantity." << endl;
					cout << "1-change the quantity you want\n" << "2-Exit\n" << "Enter your choice:";
					cin >> quantitychoice;
					if (quantitychoice == 1)
						continue;
					else
						break;
				}
				else if (productwant < 1)
					cout << "please enter valid qunatity,you enterd 0 or negative value." << endl;
				else
				{
					*Quantity -= productwant;
					reservation.push_back("Name:" + n + "\nPhone:" + p + "\nProduct name:" + *Name + "\nQuantity:" + to_string(productwant));
					cout << "The reservation process has been completed successfully." << endl;
					break;
				}

			}
			else
			{
				cout << "The quantity of this product is over" << endl;
				break;
			}
		}


	}
}
