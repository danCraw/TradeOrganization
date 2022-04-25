#pragma once
#include "Product.h"

class Towel : public Product
{
private:
	Date dateOfManufacture;
	int height;
	int width;
public:
	Towel(Date dateOfManufacture, int price, int height, int width) :
		Product(dateOfManufacture, price, "Towel") {
		this->height = height;
		this->width = width;
	}

	int getWigth() { return width; }

	int getHeight() { return height; }

};

