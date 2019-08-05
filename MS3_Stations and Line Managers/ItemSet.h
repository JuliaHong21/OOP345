/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 02 Aug 2019
 */

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include "Utilities.h"
//#include <vector>

namespace sict {
	class ItemSet {
		std::string name;
		unsigned int serialNum;
		unsigned int Qty;
		std::string desc; //description;
		Utilities util;

	public:		
		ItemSet(const std::string& str); 
		ItemSet(ItemSet&& src); //move constructor
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator-- ();
		void display(std::ostream& os, bool full) const;

		ItemSet(const ItemSet&) = delete; //disables copy construction
		ItemSet& operator= (const ItemSet&) = delete; //disables copy assignment
		ItemSet& operator= (ItemSet&&) = delete; //disables move assignment
	};
}

#endif