#include "Warehouse.h"

list<Asset*> Warehouse::sell(WholesaleClient& client, int amountAssets)
{
	list<Asset*> buyedAssets;
	int countAssets = 0;
	bool notEnoughMoney = false;
	std::list<Asset*> productsAssets = getProductsAssets();
	while (this->checkProuctAssetForAvailability(client) && countAssets < amountAssets) {
		for (std::list<Asset*>::iterator asset = getProductsAssets().begin(); asset != getProductsAssets().end(); asset++) {
			if ((*asset)->getProduct()->getType() == client.getNecessaryProductTypeForOrder()
				&& (*asset)->getAmountProducts() == client.getAmountProductsForOrder())
			{
				if (true) {
					client.setMoney(client.getMoney() - (*asset)->getPrice());
					buyedAssets.push_back(*asset);
					countAssets++;
					asset = productsAssets.erase(asset);
					setProductsAssets(productsAssets);
					break;
				}
				else
				{
					notEnoughMoney = true;
					std::cout << "not enough money\n";
					break;
				}
			}
		}
	}
	return buyedAssets;
}

void Warehouse::showProducts() {
	cout << "Warehouse products" << endl;
	for (Asset* a : getProductsAssets()) {
		cout << a->getProduct()->getType() << endl;
		cout << a->getAmountProducts() << endl;
	}
}