#include "Shop.h"

void Shop::orderProductFromWarehouse(RetailClient* client, int amountAssets) {
	setAmountProductsForOrder(client->getAmountProductsForOrder());
	setNecessaryProductTypeForOrder(client->getNecessaryProductTypeForOrder());
	if (this->warehouse->checkProuctAssetForAvailability(*this)) {
		list<Asset*> buyedAssets = warehouse->sell(*this, amountAssets);
		for (std::list<Asset*>::iterator asset = buyedAssets.begin(); asset != buyedAssets.end(); asset++) {
			getProductsAssets().push_back(*asset);
		}
	}
	else {
		std::cout << "no required product\n";
	}
	setAmountProductsForOrder(0);
	setNecessaryProductTypeForOrder("");
}

void Shop::sell(RetailClient* client, int amountAssets) {
	bool buyCompleted = false;
	bool notEnoughMoney = false;
	int countAssets = 0;
	list<Asset*>& productsAssets = getProductsAssets();
	while (this->checkProuctAssetForAvailability(client) && countAssets < amountAssets  && !notEnoughMoney)
	{
		for (list<Asset*>::iterator it = getProductsAssets().begin(); it != getProductsAssets().end();)
		{
			if ((*it)->getProduct()->getType() == client->getNecessaryProductTypeForOrder()
				&& (*it)->getAmountProducts() == client->getAmountProductsForOrder()) {
				if (checkClientMoney(*it, client)) {
					getProductsAssets().erase(it);
					client->setMoney(client->getMoney() - (*it)->getPrice());
					setMoney(getMoney() + (*it)->getPrice());
					buyCompleted = true;
					countAssets++;
					break;
				}
				else { 
					notEnoughMoney = true;
					std::cout << "not enough money\n"; 
					break;
				}
			}
			else { ++it; }
			}
		}
	if (!this->checkProuctAssetForAvailability(client) && buyCompleted) {
		std::cout << "order products\n";
		orderProductFromWarehouse(client, 5);
	}
}

void Shop::showProducts() {
	cout << "Shop products"<< endl;
	for (Asset* a : getProductsAssets()) {
		cout << a->getProduct()->getType() << endl;
		cout << a->getAmountProducts() << endl;
	}
}