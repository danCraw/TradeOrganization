#pragma once
#include "Asset.h"
#include "Client.h"
#include<iostream>
#include <list>

class Seller
{	
private:
	std::list<Asset*> productsAssets;
public:
	Seller() {}

	Seller(list<Asset*> products) {
		this->productsAssets = products;
	}

	virtual void sell() {};
	virtual void showProducts() {};

	bool checkClientMoney(Asset* productAsset, Client* client);
	bool checkProuctAssetForAvailability(Client* client);

	list<Asset*>& getProductsAssets() { return productsAssets; }
	void setProductsAssets(list<Asset*> productsAssets) { this->productsAssets = productsAssets; }
};