#pragma once
#include "Product.h"

class Milk : public Product
{
private:
	Date dateOfManufacture;
	Date expirationDate;
	float fatPercent;
public:
	Milk(Date dateOfManufacture, int price, Date expirationDate, float fatPercent) :
		Product(dateOfManufacture, price, "Milk") {
		this->expirationDate = expirationDate;
		this->fatPercent = fatPercent;
	}
	Date getExpirationDate() { return expirationDate; }

	float getFatPercent() { return fatPercent; }
	
};