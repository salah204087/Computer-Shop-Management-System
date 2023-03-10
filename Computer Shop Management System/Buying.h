#pragma once
#include "Computer.h"
#include"SignUp.h"
#include <list>
using namespace std;
class Buying:public Computer,public SignUp
{
protected:
	list <string> report;
	list<string> LocationOrder;
	list <string> reservation;
public:
	Buying(list <string> report, list<string> LocationOrder, list <string> reservation);
	Buying();
	~Buying();
	void BuyingProcess(string n,string p);
	void DisplayReports();
	void DisplayLocationOrders();
	void DisplayReservation();
	void BuyingSteps(string n,string p);
};

