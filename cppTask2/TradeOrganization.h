#pragma once
#include "Shop.h"
#include "Warehouse.h"

class TradeOrganization {
private:
	Shop* shop;
	Warehouse* warehouse;
public:
	TradeOrganization(Shop* shop, Warehouse* warehouse) {
		this->shop = shop;
		this->warehouse = warehouse;
	}

	void setShop(Shop* s) { this->shop = s; }
	void setWarehouse(Warehouse* w) { this->warehouse = w; }

	Shop* &getShop() { return shop; }
	Warehouse* &getWarehouse() { return warehouse; }
};

