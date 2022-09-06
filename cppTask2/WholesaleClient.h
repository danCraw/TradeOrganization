#pragma once
#include <iostream>
#include "Client.h"
#include "Asset.h"
using namespace std;


class WholesaleClient : public Client {
    map<Asset*, int> productsAssetsForPurchase;

public:
	WholesaleClient() {}

	WholesaleClient(int money, map<Asset*, int> productsAssetsForPurchase) : Client(money) {
        this->productsAssetsForPurchase = productsAssetsForPurchase;
    }

    map<Asset *, int> &getProductsAssetsForPurchase() {
        return productsAssetsForPurchase;
    }

    void setProductsAssetsForPurchase(map<Asset*, int> &productsAssets) {
        this->productsAssetsForPurchase = productsAssets; }
};