#pragma once
#include <iostream>
#include "Client.h"

class RetailClient : public Client {
public:
	RetailClient(int money, list<Asset*> productsAssets)
		: Client(money, productsAssets) {}
};