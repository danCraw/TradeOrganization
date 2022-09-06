#include "Seller.h"

bool Seller::checkClientMoney(Asset* productAsset, Client* client) {
	if (productAsset->getPrice() > client->getMoney()) {
		return false;
	}
	return true;
}


bool Seller::checkProuctAssetForAvailability(Asset* asset) {
	if (getProductsAssets()->size() != 0) {
		for (Asset* a : *getProductsAssets()) {
			if (a == asset)
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}


bool Seller::checkAmountProductAssetForAvailability(Asset* asset, int amountAssets) {
	int assetCounter = 0;
	if (getProductsAssets()->size() != 0) {
		for (Asset* a : *getProductsAssets()) {
			if (a == asset)
			{
				assetCounter++;
			}
		}
	}
	return (assetCounter >= amountAssets);
}

