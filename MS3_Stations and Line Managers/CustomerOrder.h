/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 02 Aug 2019
 */

#ifndef SICT_CUSTOMERORDER_H
#define SICT_CUSTOMERORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
	class CustomerOrder {
		Utilities util;
		std::string custName;
		std::string proName;
		struct ItemInfo {
			std::string itemName;
			unsigned int serialNum;  //serial number
			bool status = false;  //filled status			
		} *itemInfo;
		size_t itemNum = 0;
		static size_t width;  //field width: to be used in displaying customer names 

	public:
		CustomerOrder(); //A default constructor  
		CustomerOrder(const std::string & str); //A one-argument constructor 		
		CustomerOrder& operator=(CustomerOrder&&) noexcept; //Move assignment
		CustomerOrder(CustomerOrder&&); //move constructor
		~CustomerOrder();  //destructor
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string&) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;
		
		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
	};
}

#endif