#include<iostream>
#include <list>
#include "Computer.h"
#include "SignUp.h"
#include "Buying.h"
using namespace std;
int main()
{
	string name, phone;
	int choice;
	Buying buy;
	while(true)
	{
		cout << "1-Sign Up\n" << "2-Log in as user\n" <<"3-Log in as admin\n" <<"4-Exit\n" << "Enter your choice:";
		cin >> choice;
		if (choice == 1)
			buy.sign();
		else if (choice == 2)
		{
			tie(name, phone) = buy.LogInUser();
			while (true)
			{
				int userchoice;
				cout << "1-Show all products\n" << "2-Show software product\n" << "3-show hardware product\n" << "4-Buying\n" <<"5-Add Money\n" << "6-Exit\n" << "Enter your choice:" << endl;
				cin >> userchoice;
				if (userchoice == 1)
					buy.DispalyAllProduct();
				else if (userchoice == 2)
					buy.GetSoftProduct();
				else if (userchoice == 3)
					buy.GetHardProduct();
				else if (userchoice == 4)
					buy.BuyingProcess(name, phone);
				else if (userchoice == 5)
					buy.AddMoney(name);
				else
					break;
			}
		}
		else if (choice == 3)
		{
			buy.LogInAdmin();
			int adminchoice;
			while (true)
			{
				cout << "1-Add Product\n" << "2-Show all products\n" << "3-Show software product\n" << "4-show hardware product\n" << "5-Show Reports\n" << "6-Show Orders\n" << "7-show reservation\n" << "8-Change quantity\n" << "9-Change price\n" << "10-show all users\n" << "11-Exit\n";
				cout << "Enter your choice:";
				cin >> adminchoice;
				if (adminchoice == 1)
					buy.add_product();
				else if (adminchoice == 2)
					buy.DispalyAllProduct();
				else if (adminchoice == 3)
					buy.GetSoftProduct();
				else if (adminchoice == 4)
					buy.GetHardProduct();
				else if (adminchoice == 5)
					buy.DisplayReports();
				else if (adminchoice == 6)
					buy.DisplayLocationOrders();
				else if (adminchoice == 7)
					buy.DisplayReservation();
				else if (adminchoice == 8)
					buy.ChangeQuantity();
				else if (adminchoice == 9)
					buy.ChangePrice();
				else if (adminchoice == 10)
					buy.DisplayAllUsers();
				else
					break;
			}
		}
		else
			break;
	}
	
}