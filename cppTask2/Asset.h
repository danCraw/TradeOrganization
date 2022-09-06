#pragma once
#include "Product.h"


class Asset {
private:
	Product* product;
	int amountProducts;
	int price;
public:
	Asset(Product* product, int amountProducts) {
		this->product = product;
		this->amountProducts = amountProducts;
		this->price = (product->getPrice() * amountProducts);
	}
	
	Product* getProduct(){ return product; }
	int getAmountProducts(){ return amountProducts; }
	int getPrice(){ return price; }
};