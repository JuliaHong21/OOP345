/*
 name: Youngeun Hong
 ID: 159100171
 Email: yhong38@myseneca.ca
 Date: 2019-06-27 */

#include "Product.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>

extern int FW;  //field width

namespace sict {	

	Product::Product() {};  //defalt constructor

	Product::Product(int num_pro, double bTax) {  //receives and stores the product number and its price before tax
		numOfPro = num_pro;
		priceBTax = bTax;
	}

	double Product::price() const { return priceBTax; } //returns the price of a product

	void Product::display(std::ostream& os) const {
		os << std::setw(FW) << std::right << numOfPro
		   << std::setw(FW) << std::fixed << std::setprecision(2) << std::right << priceBTax;				
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) { //inserts the product information into the stream os.
		p.display(os);
		os << std::endl;
		return os;
	}

	iProduct* readRecord(std::ifstream& file) {
		iProduct* product;
		int number = 0;
		double price = 0;
		std::string str = {};
		char tax = '\0';

		std::getline(file, str);  //get strings from the file
		int count = std::count(str.begin(), str.end(), ' ');  //count the number of strings
		std::stringstream stream(str);

		if (count == 2) {  //if there is tax
			stream >> number >> price >> tax;
			product = new TaxableProduct(number, price, tax);
		}
		else {  //no tax
			stream >> number >> price;
			product = new Product(number, price);
		}
		return product;
	}

	//A three-argument constructor 
	TaxableProduct::TaxableProduct(int pNum, double pPrice, char tStatus) :Product(pNum, pPrice) 
		, tRate(tStatus == 'H' ? 0.13 : 0.08) {	}	
	
	double TaxableProduct::price() const {  //returns the price of a product tax included.
		return Product::price() * (tRate + 1);
	}

	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		tType == Tax::HSP ? os << " HST" : os << " PST";
	}
}