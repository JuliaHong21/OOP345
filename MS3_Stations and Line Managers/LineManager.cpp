/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 02 Aug 2019
 */

#include "LineManager.h"
#include "Station.h"

namespace sict {
	//moves the customer orders to the front of a queue holding the orders waiting to be filled 
	//and determines the index of the last station on the line.  
	LineManager::LineManager(std::vector<Station*>& station_add, std::vector<size_t>& next_idx,
	    std::vector<CustomerOrder>& cust_order, size_t start_idx, std::ostream& os)
		: stationAddr(station_add), nextIdx(next_idx), startIdx(start_idx)	{ 
		
		for(auto i = 0; i < cust_order.size(); i++)
			custOrder.push(std::move(cust_order[i]));	

		for (lastIdx = startIdx; nextIdx[lastIdx] < stationAddr.size();)
			lastIdx = nextIdx[lastIdx];

		orderSize = cust_order.size();
	}

	void LineManager::display(std::ostream& os) const {
		//displays the completed and incomplete orders at the end of the line. 
		os << "COMPLETED ORDERS" << std::endl;
		for (auto& i : complete)
			i.display(os, true);
		os << std::endl;

		os << "INCOMPLETE ORDERS" << std::endl;
		for (auto& i : incomplete)
			i.display(os, true);
	}

	bool LineManager::run(std::ostream& os) {
		if (!custOrder.empty()) {  //If there is a customer order 
			*stationAddr[startIdx] += std::move(custOrder.front()); //moves it to the starting station on the line
			custOrder.pop();
		}

		Station* tmp;
		for (size_t i = 0; i < stationAddr.size(); i++) {
			tmp = stationAddr[i];
			tmp->fill(os);
		}

		Station* tmp_last = stationAddr[lastIdx];
		for (size_t i = 0; i < stationAddr.size(); i++) {
			if (stationAddr[i]->hasAnOrderToRelease()) {
				CustomerOrder tmp_cust;
				tmp = stationAddr[i];
				tmp->pop(tmp_cust);
				os << " --> " << tmp_cust.getNameProduct() << " moved from " << tmp->getName();
				if (tmp == tmp_last) {
					//If the station is the last one, this function moves the order to the completed 
					//or incomplete set as appropriate
					os << (tmp_cust.isFilled() ? " to Completed Set\n" : " to Incomplete Set\n");
					if (tmp_cust.isFilled()) 
						complete.push_back(std::move(tmp_cust));					
					else 
						incomplete.push_back(std::move(tmp_cust));					
				}
				else {  
					//If the station is not the last station
					//this function moves the order to the next station.
					os << " to " << stationAddr[nextIdx[i]]->getName() << std::endl;
					stationAddr[nextIdx[i]]->operator+=(std::move(tmp_cust));
				}
			}
		}
		//This function returns true if all the orders have been processed; false otherwise.
		bool end = (orderSize == complete.size() + incomplete.size());
		return end;
	}
}