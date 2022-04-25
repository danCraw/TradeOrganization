#pragma once
#include <iostream>
#include "Client.h"
#include "Asset.h"
using namespace std;


class WholesaleClient : public Client {
public:
	WholesaleClient() {}

	WholesaleClient(int money, string necessaryProductType, int amountProducts) 
		: Client(money, necessaryProductType, amountProducts) {}

	/*bool checkClientMoney(Asset* productAsset, Client* client) {
		if (productAsset->getPrice() > client->getMoney()) {
			return false;
		}
		return true;
	}*/
};