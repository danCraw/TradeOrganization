#include "Seller.h"

bool Seller::checkClientMoney(Asset* productAsset, Client* client) {
	if (productAsset->getPrice() > client->getMoney()) {
		return false;
	}
	return true;
}

bool Seller::checkProuctAssetForAvailability(Client* client) {
	if (getProductsAssets().size() != 0) {
		for (Asset* a : getProductsAssets()) {
			if (a->getProduct()->getType() == client->getNecessaryProductTypeForOrder()
				&& a->getAmountProducts() == client->getAmountProductsForOrder())
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