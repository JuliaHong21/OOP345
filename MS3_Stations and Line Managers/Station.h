/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 02 Aug 2019
 */

#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <string> 
#include <iostream>
#include <queue>
#include "CustomerOrder.h"

namespace sict {
	class Station {
		ItemSet itemSet;
		std::queue<CustomerOrder> CustOrder;
	public:
		Station(const Station&) = delete;  
		Station(const Station&&) = delete; 
		Station& operator=(Station&&) = delete; 
		Station& operator=(const Station&&) = delete; 

		Station(const std::string& str);
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;
	};
}
#endif