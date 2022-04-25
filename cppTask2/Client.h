#pragma once
#include <iostream>
using namespace std; 


class Client
{
private:
	int money;
	string necessaryProductType;
	int amountProducts;
public:
	Client() {}

	Client(int money, string necessaryProductType, int amountProducts) {
		this->money = money;
		this->necessaryProductType = necessaryProductType;
		this->amountProducts = amountProducts;
	}

	void setMoney(int money) { this->money = money; }

	int getMoney() { return money; }
	string getNecessaryProductTypeForOrder() { return necessaryProductType; }
	int getAmountProductsForOrder() { return amountProducts; }

	void setNecessaryProductTypeForOrder(string necessaryProductType) { this->necessaryProductType = necessaryProductType; }
	void setAmountProductsForOrder(int amountProductsForOrder) { this->amountProducts = amountProductsForOrder; }
};

