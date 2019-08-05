/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 02 Aug 2019
 */

#include "Station.h"
#include "ItemSet.h"

namespace sict {
	Station::Station(const std::string& str): itemSet(str){	
	}

	void Station::display(std::ostream& os) const {
		itemSet.display(os, true); 
	}

	void Station::fill(std::ostream& os) {
		if (!CustOrder.empty()) { //if there is one,		
			CustOrder.back().fillItem(itemSet, os); //fills the last order in the customer order queue
		}
	}

	const std::string& Station::getName() const {
		return itemSet.getName(); //returns a reference to the name of the ItemSet sub-object
	}

	bool Station::hasAnOrderToRelease() const {
		bool releaseState = false;
		if (!(CustOrder.empty() || (!(CustOrder.front().isItemFilled(itemSet.getName())
			|| itemSet.getQuantity() == 0)))){
			releaseState = true;
		}		
		return releaseState;
	}

	Station& Station::operator--() {
		--itemSet;  //decrements the number of items in the ItemSet
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		CustOrder.push(std::move(order)); //moves the order to the back of the station’s queue
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		//removes the order at the front of the queue and moves it to the calling function through the parameter list. 
		//This function returns true if the station filled its part of the order; false otherwise. 
		//If there are no orders in the queue, this function returns false. 
		bool filled = false;
		if (!CustOrder.empty()) {
			ready = std::move(CustOrder.front());
			CustOrder.pop();
			if (ready.isItemFilled(itemSet.getName())) {
				filled = true;
			}
		}	
		return filled;
	}

	void Station::validate(std::ostream& os) const { //reports the state of the ItemSet object 		
		os << " getName(): " << itemSet.getName() << std::endl; //getName() : ITEM
		os << " getSerialNumber(): " << itemSet.getSerialNumber() << std::endl;  //getSerialNumber() : SERIAL NUMBER
		os << " getQuantity(): " << itemSet.getQuantity() << std::endl;  //getQuantity() : NUMBER_OF_ITEMS_LEFT
	}
}