#include "Computer.h"
#include<iostream>
#include <string>
#include <vector>
using namespace std;
Computer::Computer(list <string>NameProduct, list <string>type, list <double>PriceProduct, list <int>QuantityProduct, list <string>DetailsProduct, list <int>id)
{
	this->NameProduct = NameProduct;
	this->type = type;
	this->PriceProduct = PriceProduct;
	this->QuantityProduct = QuantityProduct;
	this->DetailsProduct = DetailsProduct;
	this->id = id;
}

Computer::Computer()
{

}

Computer::~Computer()
{
}

void Computer::add_product()
{
	string Name,Type,Details;
	double Price;
	int Quantity,Id;
	cout << "1-Software\n" << "2-Hardware" << endl;
	while(true)
	{
		cout << "Enter the Type of product:";
		getline(cin >> ws, Type);
		if (Type == "1" || Type == "Software" || Type == "software")
		{
			type.push_back("Software");
			AddSoftwareCategory();
			break;
		}
		else if (Type == "2" || Type == "Hardware" || Type == "hardware")
		{
			type.push_back("Hardware");
			AddHardwareCategory();
			break;
		}
		else
		{
			cout << "please enter valid choice"<<endl;
			continue;
		}
	}
	cout << "Enter the name of product:";
	getline(cin>>ws, Name);
	NameProduct.push_back(Name);
	cout << "Enter the price of product:";
	cin>>Price;
	PriceProduct.push_back(Price);
	cout << "Enter the quantity of product:";
	cin >> Quantity;
	QuantityProduct.push_back(Quantity);
	cout << "Enter the details of product:";
	getline(cin >> ws, Details);
	DetailsProduct.push_back(Details);
	Id= rand() %50000;
	id.push_back(Id);
}

 void Computer:: DispalyAllProduct()
{
	 auto N = NameProduct.begin();
	 auto T = type.begin();
	 auto I = id.begin();
	 auto P = PriceProduct.begin();
	 auto Q = QuantityProduct.begin();
	 auto D = DetailsProduct.begin();
	 while (!NameProduct.empty()) {
		 cout << "Name:" << *N << endl;
		 cout << "Type:" << *T << endl;
		 cout << "ID:" << *I << endl;
		 cout << "Price:" << *P << endl;
		 cout << "Quantity:" << *Q << endl;
		 cout << "Details:" << *D << endl;
		 cout << "				*********************************************				" << endl;
		 ++N;
		 ++T;
		 ++P;
		 ++I;
		 ++Q;
		 ++D;
		 if (N == NameProduct.end())
			 break;

	 }
}

void Computer::GetSoftProduct()
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
		vector<int> indices;
		int index = 0;
		for (auto it = type.begin(); it != type.end(); ++it) {
			if (*it == "Software") {
				indices.push_back(index);
			}
			index++;
		}
		for (int i = 0; i < indices.size(); ++i) {
			int index = indices[i];
			auto Name = NameProduct.begin();
			auto Id = id.begin();
			auto Price = PriceProduct.begin();
			auto Quantity = QuantityProduct.begin();
			auto Details = DetailsProduct.begin();
			advance(Name, index);
			advance(Id, index);
			advance(Price, index);
			advance(Quantity, index);
			advance(Details, index);
			cout << "Name:" << *Name << "\nID:" << *Id << "\nPrice:" << *Price << "$\n" << "Quantity:" << *Quantity << "\nDetails:" << *Details << endl;
			cout << "			*************************************************			" << endl;
		}
	}
	else
		cout << "No software products added."<<endl;
}

void Computer::GetHardProduct()
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
		vector<int> indices;
		int index = 0;
		for (auto it = type.begin(); it != type.end(); ++it) {
			if (*it == "Hardware") {
				indices.push_back(index);
			}
			index++;
		}
		for (int i = 0; i < indices.size(); ++i) {
			int index = indices[i];
			auto Name = NameProduct.begin();
			auto Id = id.begin();
			auto Price = PriceProduct.begin();
			auto Quantity = QuantityProduct.begin();
			auto Details = DetailsProduct.begin();
			advance(Name, index);
			advance(Id, index);
			advance(Price, index);
			advance(Quantity, index);
			advance(Details, index);
			cout << "Name:" << *Name << "\nID:" << *Id << "\nPrice:" << *Price << "$\n" << "Quantity:" << *Quantity << "\nDetails:" << *Details << endl;
			cout << "			*************************************************			" << endl;
		}
	}
	else
		cout << "No hardware products added." << endl;
}

void Computer::ChangeQuantity()
{
	int choice;
	string name_product;
	while(true)
	{
		cout << "1-show all products\n" << "2-show software products\n" << "3-show hardware products\n" << "4-Exit\n";
		cout << "enter the number of choice:";
		cin >> choice;
		if (choice == 1)
		{
			DispalyAllProduct();
			while (true)
			{
				int index = 0;
				int check = -1;
				cout << "Enter name of products you want to change the quantity:";
				getline(cin >> ws, name_product);
				for (auto it = NameProduct.begin(); it != NameProduct.end(); ++it) {
					if (*it == name_product) {
						check++;
						break;
					}
					index++;
				}
				if (check != -1)
				{
					int newquantity = 0;
					auto it = QuantityProduct.begin();
					advance(it, index);
					while (true)
					{
						cout << "Enter the new quantity for product:";
						cin >> newquantity;
						if (newquantity >= 0)
						{
							*it = newquantity;
							break;
						}
						else
							cout << "please enter valid quantity(You entered a negative value)." << endl;
					}
					break;
				}
				else
					cout << "You entered worng name please enter valid name" << endl;
			}
		}
		else if (choice == 2)
		{
			GetSoftProduct();
			while (true)
			{
				int index = 0;
				int check = -1;
				cout << "Enter name of products you want to change the quantity:";
				getline(cin >> ws, name_product);
				for (auto it = NameProduct.begin(); it != NameProduct.end(); ++it) {
					if (*it == name_product) {
						check++;
						break;
					}
					index++;
				}
				if (check != -1)
				{
					int newquantity = 0;
					auto it = QuantityProduct.begin();
					advance(it, index);
					while (true)
					{
						cout << "Enter the new quantity for product:";
						cin >> newquantity;
						if (newquantity >= 0)
						{
							*it = newquantity;
							break;
						}
						else
							cout << "please enter valid quantity(You entered a negative value)." << endl;
					}
					break;
				}
				else
					cout << "You entered worng name please enter valid name" << endl;
			}
		}
		else if (choice == 3)
		{
			GetHardProduct();
			while (true)
			{
				int index = 0;
				int check = -1;
				cout << "Enter name of products you want to change the quantity:";
				getline(cin >> ws, name_product);
				for (auto it = NameProduct.begin(); it != NameProduct.end(); ++it) {
					if (*it == name_product) {
						check++;
						break;
					}
					index++;
				}
				if (check != -1)
				{
					int newquantity = 0;
					auto it = QuantityProduct.begin();
					advance(it, index);
					while (true)
					{
						cout << "Enter the new quantity for product:";
						cin >> newquantity;
						if (newquantity >= 0)
						{
							*it = newquantity;
							break;
						}
						else
							cout << "please enter valid quantity(You entered a negative value)." << endl;
					}
					break;
				}
				else
					cout << "You entered worng name please enter valid name" << endl;
			}
		}
		else
			break;
	}
}

void Computer::ChangePrice()
{
	int choice;
	int index = -1;
	string name_product;
	cout << "1-show all products\n" << "2-show software products\n" << "3-show hardware products\n";
	while (true)
	{
		cout << "enter the number of choice:";
		cin >> choice;
		if (choice == 1)
		{
			DispalyAllProduct();
			cout << "Enter name of products you want to change the price:";
			getline(cin >> ws, name_product);
			for (auto it = NameProduct.begin(); it != NameProduct.end(); ++it) {
				if (*it == name_product) {
					break;
				}
				index++;
			}
			if (index > 0)
			{
				int newprice = 0;
				auto it = PriceProduct.begin();
				advance(it, index);
				while (true)
				{
					cout << "Enter the new price for product:";
					cin >> newprice;
					if (newprice > 0)
					{
						*it = newprice;
						break;
					}
					else
						cout << "please enter valid price(You entered a negative value)." << endl;
				}
			}
		}
		else if (choice == 2)
		{
			GetSoftProduct();
			cout << "Enter name of products you want to change the price:";
			getline(cin >> ws, name_product);
			for (auto it = NameProduct.begin(); it != NameProduct.end(); ++it) {
				if (*it == name_product) {
					break;
				}
				index++;
			}
			if (index > 0)
			{
				int newprice = 0;
				auto it = PriceProduct.begin();
				advance(it, index);
				while (true)
				{
					cout << "Enter the new price for product:";
					cin >> newprice;
					if (newprice > 0)
					{
						*it = newprice;
						break;
					}
					else
						cout << "please enter valid price(You entered a negative value)." << endl;
				}
			}
		}
		else if (choice == 3)
		{
			GetHardProduct();
			cout << "Enter name of products you want to change the price:";
			getline(cin >> ws, name_product);
			for (auto it = NameProduct.begin(); it != NameProduct.end(); ++it) {
				if (*it == name_product) {
					break;
				}
				index++;
			}
			if (index > 0)
			{
				int newprice = 0;
				auto it = PriceProduct.begin();
				advance(it, index);
				while (true)
				{
					cout << "Enter the new price for product:";
					cin >> newprice;
					if (newprice > 0)
					{
						*it = newprice;
						break;
					}
					else
						cout << "please enter valid price(You entered a negative value)." << endl;
				}
			}
		}
		else
			cout << "you enterd unvalid choice,please enter valid choice." << endl;
	}
}
