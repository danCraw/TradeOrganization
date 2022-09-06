#include "Shop.h"

void Shop::orderProductsFromWarehouse(map<Asset*, int>* assetsForOrder) {
    this->setProductsAssetsForPurchase(*assetsForOrder);
	setProductsAssetsForPurchase(*assetsForOrder);
    for(map<Asset*, int>::iterator it = assetsForOrder->begin(); it != assetsForOrder->end(); ++it) {
        if (this->warehouse->checkProuctAssetForAvailability(it->first)) {
            list<Asset *>* buyedAssets = warehouse->sell(&*this);
            for (std::list<Asset *>::iterator asset = buyedAssets->begin(); asset != buyedAssets->end(); asset++) {
                getProductsAssets()->push_back(*asset);
            }
            delete buyedAssets;
        } else {
            std::cout << "no required product\n";
        }
    }
}

list<Asset*>* Shop::sell(Client* client) {
	if (dynamic_cast<RetailClient*>(client)) {
        bool buyCompleted = false;
        bool notEnoughMoney = false;
        map<Asset*, int> *assetsForOrder = new map<Asset*, int>;
        bool orderAssets = false;
        int countAssets = 0;
        list<Asset *>* productsAssets = getProductsAssets();
        for (Asset *a: client->getProductsAssetsForPurchase()) {
            while (this->checkProuctAssetForAvailability(a) && !notEnoughMoney) {
                for (list<Asset *>::iterator it = getProductsAssets()->begin(); it != getProductsAssets()->end();) {
                    if (*it == a) {
                        if (checkClientMoney(*it, client)) {
                            int b = getMoney();
                            Asset* c =  (*it);
                            client->setMoney(client->getMoney() - (*it)->getPrice());
                            setMoney(getMoney() + (*it)->getPrice());
                            buyCompleted = true;
                            countAssets++;
                            getProductsAssets()->erase(it);
                            break;
                        } else {
                            notEnoughMoney = true;
                            std::cout << "not enough money\n";
                            break;
                        }
                    } else { ++it; }
                }
            }
            for (Asset *a: client->getProductsAssetsForPurchase()) {
                if (!this->checkProuctAssetForAvailability(a) && buyCompleted) {
                    assetsForOrder->insert(std::pair<Asset* ,int>(a, 5));
                    orderAssets = true;
                }
            }
            if (orderAssets){
                std::cout << "order products\n";
                orderProductsFromWarehouse(assetsForOrder);
            }
            delete assetsForOrder;
            return NULL;
        }
    }
	return NULL;
}



void Shop::showProducts() {
	cout << "Shop products"<< endl;
	for (Asset* a : *getProductsAssets()) {
		cout << a->getProduct()->getType() << endl;
		cout << a->getAmountProducts() << endl;
	}
}