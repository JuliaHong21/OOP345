/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 02 Aug 2019
 */

#ifndef SICT_LINEMANAGER_H
#define SICT_LINEMANAGER_H

#include "CustomerOrder.h"
#include "Station.h"
#include <string>
#include <queue>

namespace sict {
	class LineManager {
		std::vector<Station*> stationAddr;
		std::vector<size_t> nextIdx;		
		std::queue<CustomerOrder> custOrder;
		std::vector<CustomerOrder> complete, incomplete;
		size_t startIdx, lastIdx, orderSize;
		std::ostream* oStream;		
	public:		
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&,
					size_t, std::ostream& os); //Constructor with 5 arguments
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};
}
#endif