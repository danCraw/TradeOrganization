#pragma once
#include "Date.h"
#include <iostream>
using namespace std;

class Product
{
private:
	Date dateOfManufacture;
	int price;
	string type;
public:
	Product(Date dateOfManufacture, int price, string type) {
		this->dateOfManufacture = dateOfManufacture;
		this->price = price;
		this->type = type;
	}

	Date getDateOfManufacture() { return dateOfManufacture; }
	int getPrice() { return price; }
	string getType() { return type; }
};

