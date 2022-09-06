#include "Warehouse.h"

list<Asset*>* Warehouse::sell(Client* client) {
    if (dynamic_cast<WholesaleClient *>(client)) {
        list<Asset *> *buyedAssets = new list<Asset *>;
        int countAssets = 0;
        for(map<Asset*, int>::iterator it = dynamic_cast<WholesaleClient *>(client)->getProductsAssetsForPurchase().begin();
        it != dynamic_cast<WholesaleClient *>(client)->getProductsAssetsForPurchase().end(); ++it) {
            map<Asset*, int> b = dynamic_cast<WholesaleClient *>(client)->getProductsAssetsForPurchase();
            while (this->checkProuctAssetForAvailability((*it).first) && countAssets < (*it).second) {
                for (std::list<Asset *>::iterator asset = getProductsAssets()->begin();
                     asset != getProductsAssets()->end(); asset++) {
                    if (*asset == it->first) {
                        if (checkClientMoney(*asset, client)) {
                            client->setMoney(client->getMoney() - (*asset)->getPrice());
                            buyedAssets->push_back(*asset);
                            countAssets++;
                            asset = getProductsAssets()->erase(asset);
                            setProductsAssets(getProductsAssets());
                            break;
                        } else {
                            std::cout << "not enough money\n";
                            break;
                        }
                    }
                }
            }
            return buyedAssets;
        }
        return NULL;
    }
}

void Warehouse::showProducts() {
	cout << "Warehouse products" << endl;
	for (Asset* a : *getProductsAssets()) {
		cout << a->getProduct()->getType() << endl;
		cout << a->getAmountProducts() << endl;
	}
}