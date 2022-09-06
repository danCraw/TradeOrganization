#pragma once
#include "Warehouse.h"
#include "WholesaleClient.h"
#include "RetailClient.h"
using namespace std;

class Shop : public WholesaleClient, public Seller {
private:
	Warehouse* warehouse;
public:
	Shop(Warehouse* warehouse, map<Asset*, int> prouctsForOrder, list<Asset*>* products, int money) :
		WholesaleClient(money, prouctsForOrder), Seller(products) {
		this->warehouse = warehouse;
	}

    void orderProductsFromWarehouse(map<Asset*, int>*);
	list<Asset*>* sell(Client* client);
	void showProducts();

	Warehouse* getWarehouse() { return warehouse; }
};