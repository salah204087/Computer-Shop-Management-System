#include "Hardware.h"
#include<iostream>
#include<algorithm>
Hardware::Hardware(list<string> category)
{
	this->category = category;
}

Hardware::Hardware()
{
	category = { " " };
}

Hardware::~Hardware()
{
}

void Hardware::AddHardwareCategory()
{
	    cout << "1-Laptop\n" << "2-Mouse\n" << "3-Keyboard\n" << "4-Motherboard\n" << "5-CPU\n" << "6-RAM\n" << "7-Hard drive\n" << "8-Solid-state drive\n" << "9-Optical drive\n" << "10-Heat sink\n" << "11-Graphics processing unit(GPU)\n" << "12-Network interface card\n" << "13-Microphone\n" << "14-Camera\n" << "15-Touchpad\n" << "16-USB flash drive\n" << "17-Printer" << endl;
	correct_choice:
		string userInput;
		int choice = 0;
		bool validInput = false;

		while (!validInput) {
			cout << "Enter the number of choice: ";
			getline(std::cin, userInput);

			try {
				choice = stoi(userInput);
				validInput = true;
			}
			catch (const invalid_argument& ex) {
				cout << "Invalid input. Please enter a valid number(don't input a string)." << std::endl;
			}
		}
			switch (choice)
			{
			case 1:
				category.push_back("Laptop");
				break;
			case 2:
				category.push_back("Mouse");
				break;
			case 3:
				category.push_back("Keyboard");
				break;
			case 4:
				category.push_back("Motherboard");
				break;
			case 5:
				category.push_back("CPU");
				break;
			case 6:
				category.push_back("RAM");
				break;
			case 7:
				category.push_back("Hard drive");
				break;
			case 8:
				category.push_back("Solid-state drive");
				break;
			case 9:
				category.push_back("Optical drive");
				break;
			case 10:
				category.push_back("Heat sink");
				break;
			case 11:
				category.push_back("Graphics processing unit(GPU)");
				break;
			case 12:
				category.push_back("Network interface card");
				break;
			case 13:
				category.push_back("Microphone");
				break;
			case 14:
				category.push_back("Camera");
				break;
			case 15:
				category.push_back("Touchpad");
				break;
			case 16:
				category.push_back("USB flash drive");
				break;
			case 17:
				category.push_back("Printer");
				break;
			default:
				cout << "please enter valid choice" << endl;
				goto correct_choice;
			}
		

}

void Hardware::GetHardCategory()
{
	for (auto i : category)
		cout << "Category:" << i << endl;
}
