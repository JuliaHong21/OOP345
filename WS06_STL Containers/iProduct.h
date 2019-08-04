/*
 name: Youngeun Hong
 ID: 159100171
 Email: yhong38@myseneca.ca
 Date: 2019-06-27 */

#ifndef _SICT_IPRODUCT_H
#define _SICT_IPRODUCT_H
#include <iostream>

namespace sict {
	class iProduct {
	public:
		virtual double price() const = 0;  //returns the price of a product
		virtual void display(std::ostream& os) const = 0;  //displays the information about the product
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);  //inserts the product information into the stream os.
	iProduct* readRecord(std::ifstream& file);  //reads a single record from file object file
}
#endif
