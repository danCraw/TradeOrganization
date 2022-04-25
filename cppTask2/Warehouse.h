#pragma once
#include <iostream>
#include <list>
#include "Milk.h"
#include "Towel.h"
#include "Seller.h"
#include "WholesaleClient.h"


class Warehouse : public Seller
{
public:
	Warehouse(list<Asset*> productsAssets) : Seller(productsAssets) {}

	bool checkProductAvailability(WholesaleClient& client);
	bool checkProuctAssetForAvailability(WholesaleClient& client);
	list<Asset*> sell(WholesaleClient& client, int amountAssets);
	void showProducts();
};