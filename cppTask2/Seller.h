#pragma once
#include "Asset.h"
#include "Client.h"
#include<iostream>
#include <list>


class Seller
{	
private:
	std::list<Asset*>* productsAssets;
public:
	Seller() {}

	Seller(list<Asset*>* products) {
		this->productsAssets = products;
	}

	virtual list<Asset*>* sell(Client* client) = 0;
	virtual void showProducts() = 0;

	bool checkClientMoney(Asset* productAsset, Client* client);
	bool checkProuctAssetForAvailability(Asset* asset);
    bool checkAmountProductAssetForAvailability(Asset* asset, int amountAssets);

	list<Asset*>* &getProductsAssets() { return productsAssets; }
	void setProductsAssets(list<Asset*>* productsAssets) { this->productsAssets = productsAssets; }
};