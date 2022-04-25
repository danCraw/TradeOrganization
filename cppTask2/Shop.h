#pragma once
#include "Warehouse.h"
#include "RetailClient.h"
using namespace std;

class Shop : public WholesaleClient, public Seller {
private:
	Warehouse* warehouse;
public:
	Shop(Warehouse* warehouse, list<Asset*> products, int money) :
		WholesaleClient(money, "", 0), Seller(products) {
		this->warehouse = warehouse;
	}

	void orderProductFromWarehouse(RetailClient* client, int amountAssets);
	virtual void sell(RetailClient* client, int amountAssets);
	void showProducts();

	Warehouse* getWarehouse() { return warehouse; }
};