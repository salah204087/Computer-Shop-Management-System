#pragma once
using namespace std;
#include <list>
#include <string>
#include"Software.h"
#include "Hardware.h"
class Computer:public Software,public Hardware
{
private:
	list <int>id;
protected:
	list <string>NameProduct;
	list <double>PriceProduct;
	list <int>QuantityProduct;
	list <string>DetailsProduct;
	list <string>type;

public:
	Computer(list <string>NameProduct,list <string>type, list <double>PriceProduct, list <int>QuantityProduct, list <string>DetailsProduct, list <int>id);
	Computer();
	~Computer();
	void add_product();
	void DispalyAllProduct();
	void GetSoftProduct();
	void GetHardProduct();
	void ChangeQuantity();
	void ChangePrice();
};

