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
	Warehouse(list<Asset*>* productsAssets) : Seller(productsAssets) {}

	list<Asset*>* sell(Client* client);
	void showProducts();
};