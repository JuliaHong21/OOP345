/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 19 Jul 2019
 */


#include "ItemSet.h"
#include <iomanip>

namespace sict {
	size_t Utilities::FW{ 0u }; //initialize static field width
	char Utilities::delimiter{ ' ' }; //initialize static delimiter	

	ItemSet::ItemSet(const std::string& str) {
		//extracts 4 tokens from the string, populates the object with those tokens 
		//and determines the field width to be used in displaying data for all objects of the class.
		size_t next_pos{ 0 };
		name = util.extractToken(str, next_pos);
		serialNum = stoul(util.extractToken(str, next_pos)); //convert str to unsigned int
		Qty = stoul(util.extractToken(str, next_pos)); //convert str to unsigned int
		desc = util.extractToken(str, next_pos);
	}

	ItemSet::ItemSet(ItemSet&& src) {		
		name = src.name;
		serialNum = src.serialNum;
		Qty = src.Qty;
		desc = src.desc;

		src.name = "";
		src.serialNum = 0u;
		src.Qty = 0u;
		src.desc = "";
	}

	const std::string& ItemSet::getName() const {
		return name;
	}

	const unsigned int ItemSet::getSerialNumber() const {
		return serialNum;
	}

	const unsigned int ItemSet::getQuantity() const {
		return Qty;
	}

	ItemSet& ItemSet::operator-- () { //a prefix decrement operator 
		--Qty;  //reduces the number of items in stock by one 
		++serialNum; //increases the serial number by one
		return *this;
	}

	void ItemSet::display(std::ostream& os, bool full) const {
		if (full) {
			//the data consists of the name, serial number quantity in stock 
			//and the description of the items in the set 
			os << std::setw(util.getFieldWidth())
				<< std::left << name << " "
				<< std::right << "[" << std::setw(5) << std::setfill('0') << serialNum << "] "
				<< "Quantity " << std::setfill(' ') << std::setw(3) << std::left << Qty << " "
				<< "Description: " << desc
				<< std::endl; 
		}
		else {
			//the data consists of the name of the items in the set 
			//and the next serial number to be assigned
			os << "[" << name << "][" << serialNum << "]";
		}
	}
}