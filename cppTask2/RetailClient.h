#pragma once
#include <iostream>
#include "Client.h"

class RetailClient : public Client {
public:
	RetailClient(int money, string necessaryProductType, int amountProducts)
		: Client(money, necessaryProductType, amountProducts) {}
};