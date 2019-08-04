/*
 name: Youngeun Hong
 ID: 159100171
 Email: yhong38@myseneca.ca
 Date: 2019-06-27 */

#ifndef _SICT_PRODUCT_H
#define _SICT_PRODUCT_H

#include "iProduct.h"
#include <iostream>
#include <string>

namespace sict {
	class Product : public iProduct {
		int numOfPro{ 0 };
		double priceBTax{ 0.0 };
	public:
		Product();
		Product(int pNum, double bTax);  //receives and stores the product number and its price before tax
		double price() const;
		void display(std::ostream& os) const;
	};

	class TaxableProduct :public Product {		
		double tRate; 
		enum class Tax { HSP, PST } tType;
	public:		
		TaxableProduct(int pNum, double pPrice, char tStatus); //A three-argument constructor 
		double price() const;  //returns the price of a product tax included.
		void display(std::ostream& os) const;
	};	
}
#endif
