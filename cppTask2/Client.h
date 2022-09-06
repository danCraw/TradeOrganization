#pragma once
#include "Asset.h"
#include <iostream>
#include <list>
#include <map>
using namespace std;


class Client
{
private:
	int money;
    list<Asset*> productsAssetsForPurchase;
public:
	Client() {}

	virtual ~Client() {};

	Client(int money, list<Asset*> productsAssetsForPurchase) {
		this->money = money;
		this->productsAssetsForPurchase = productsAssetsForPurchase;
	}

    Client(int money) {
        this->money = money;
    }

	void setMoney(int money) { this->money = money; }

	int getMoney() { return money; }

    list<Asset*> &getProductsAssetsForPurchase() { return productsAssetsForPurchase; }

    void setProductsAssetsForPurchase(const list<Asset *> &productsAssetsForPurchase) {
        Client::productsAssetsForPurchase = productsAssetsForPurchase;
    }
};

