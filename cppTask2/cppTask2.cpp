#include <typeinfo>									 
#include "Date.h"
#include "Product.h"
#include "Shop.h"
#include "Milk.h"
#include "Warehouse.h"
#include "TradeOrganization.h"
#include "RetailClient.h"
#include <map>
#include <list>


int main()
{
    Date* dateOfManufacture = new Date(2021, 12, 12);
    Date* expirationDate = new Date(2022, 3, 14);
    Milk* m = new Milk(*dateOfManufacture, 100, *expirationDate, 3.2);
    Towel* t = new Towel(*dateOfManufacture, 10, 3, 2);

    Asset* ma = new Asset(m, 5);
    Asset* ta = new Asset(t, 3);

    list<Asset*> clientsAssets;
    clientsAssets.push_back(ma);
    Client* rClient = new RetailClient(1000, clientsAssets);

    std::list<Asset*> *wAssets = new list<Asset*>;
    std::list<Asset*>* sAssets = new list<Asset*>;

    wAssets->push_back(ta);
    wAssets->push_back(ma);
    wAssets->push_back(ma);
    wAssets->push_back(ma);
    wAssets->push_back(ma);
    wAssets->push_back(ma);
    wAssets->push_back(ma);
    sAssets->push_back(ma);

    map<Asset*, int>* shopProductsForOrder = new map<Asset*, int>;
    Warehouse* w = new Warehouse(wAssets);
    Shop* s = new Shop(w, *shopProductsForOrder, sAssets, 10000);
    TradeOrganization* org = new TradeOrganization(s, w);
    org->getWarehouse()->showProducts();

    org->getShop()->showProducts();
    org->getShop()->sell(rClient);
    org->getShop()->showProducts();
    cout << org->getShop()->getMoney();
}