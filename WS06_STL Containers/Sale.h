/*
 name: Youngeun Hong
 ID: 159100171
 Email: yhong38@myseneca.ca
 Date: 2019-06-27 */

#ifndef _SICT_SALE_H
#define _SICT_SALE_H

#include "Product.h"
#include <vector>

namespace sict {
	class Sale {
		std::vector<iProduct*> pfile; 
	public:
		Sale(const char* Fname);  //A single argument constructor 
		void display(std::ostream& os) const;
	};
}
#endif
