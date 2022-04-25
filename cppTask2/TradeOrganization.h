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

	Shop setShop(Shop* s) { this->shop = s; }
	Warehouse setWarehouse(Warehouse* w) { this->warehouse = w; }

	Shop* getShop() { return shop; }
	Warehouse* getWarehouse() { return warehouse; }
};

