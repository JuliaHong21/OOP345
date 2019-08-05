/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 02 Aug 2019
 */

#include <iomanip>
#include "CustomerOrder.h"

namespace sict {
	size_t CustomerOrder::width = 0;
	CustomerOrder::CustomerOrder() : custName{ "" }, proName{ "" }, itemNum{ 0 }{};

	CustomerOrder::CustomerOrder(const std::string& str) {  //A one-argument constructor 
		std::vector<std::string> tk;  //token

		for (size_t i = 0; i < str.size();) {
			tk.push_back(util.extractToken(str, i));
		}

		if (tk.size() < 3) { //throws an exception- when there are less than 3 token 
			throw(std::string) "No items";
		}

		custName = tk[0];  //saves customer's name
		proName = tk[1];   //saves the name of the product
		itemInfo = new ItemInfo[tk.size() - 2]; //allocates memory for each item 
		for (size_t i = 2; i < tk.size(); i++) {
			itemInfo[i - 2].itemName = tk[i];
			itemNum++;
		}
		width = util.getFieldWidth();  //field width
	}	

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {  //Move assignment
		//delete[] itemInfo;
		if (this != &src) {
			custName = src.custName;
			proName = src.proName;
			itemNum = src.itemNum;
			width = src.width;
			itemInfo = new ItemInfo[itemNum];
			for (size_t i = 0; i < itemNum; i++) {
				itemInfo[i] = src.itemInfo[i];
			}
		}
		delete[] src.itemInfo;
		src.custName.clear();
		src.proName.clear();
		src.itemNum = 0u;
		src.itemInfo = nullptr;

		return *this;
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) {  //move constructor
		itemInfo = nullptr;
		*this = std::move(src);
	}

	CustomerOrder::~CustomerOrder() {  //destructor
		delete[] itemInfo;
		itemInfo = nullptr;
	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {  //checks each item request
		for (size_t i = 0; i < itemNum; i++) {
			if (item.getName() == itemInfo[i].itemName) {
				if ((item.getQuantity() > 0) && !itemInfo[i].status) {  //requested item is available and the request has not been filled
					itemInfo[i].status = true;
					itemInfo[i].serialNum = item.getSerialNumber();
					os << " Filled " << getNameProduct();
					item.display(os, false);	//Filled CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] 				
					--item;
				}
				else if (item.getQuantity() > 0 && itemInfo[i].status) {  //the item request has already been filled
					os << " Unable to fill " << getNameProduct();
					item.display(os, false);
					os << " already filled";  //Unable to fill CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] already filled
				}
				else if (item.getQuantity() == 0 && !itemInfo[i].status) {  //the item is out of stock
					os << " Unable to fill " << getNameProduct();
					item.display(os, false);
					os << " out of stock";   //Unable to fill CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] out of stock 
				}
				os << std::endl;
			}
		}
	}

	bool CustomerOrder::isFilled() const {  //searches the list of items requested 
		bool filled = true;
		for (size_t i = 0; i < itemNum; i++) {
			if (!itemInfo[i].status)
				filled = false;
		}
		return filled;  //returns true if all have been filled
	}

	bool CustomerOrder::isItemFilled(const std::string& item) const {  //search the item request list for that item
		bool filled = true;
		for (size_t i = 0; i < itemNum; i++) {
			if (itemInfo[i].itemName == item) {
				if (!itemInfo[i].status)
					filled = false;
			}
		}
		return filled;  //returns true if all requests for that item have been filled
	}

	std::string CustomerOrder::getNameProduct() const {  //returns the name of the customer and their product 
		return custName + " [" + proName + "]";  //CUSTOMER [PRODUCT]
	}

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {
		os << std::setw(width + 1 )<< std::left << custName << "[" << proName << "] " << std::endl;  //CUSTOMER [PRODUCT]
		for (size_t i = 0; i < itemNum; i++) {
			if (!showDetail) {
				os << std::setw(width + 1) << " " << itemInfo[i].itemName << std::endl;
			}
			else {
				os << std::setw(width + 1) << " " << "[" << itemInfo[i].serialNum << "] "; // [SERIAL NUMBER]
				os << itemInfo[i].itemName << " - ";  //ITEM -
				if (itemInfo[i].status) {
					os << "FILLED";
				}
				else {
					os << "MISSING";
				}
				os << std::endl;  //FILL_STATUS
			}
		}
	}
}