/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-23 */

#ifndef _SICT_TAXABLE_H
#define _SICT_TAXABLE_H
#include <iostream>

namespace sict {
	class Taxable {
		const float tax;
	public:
		//a one-argument constructor 
		Taxable(float tRate) : tax{ tRate } {}

		//returns the sum of the price and the tax added to it
		float operator()(float price) {
			return price * (1+tax);
		}
	};

}
#endif
