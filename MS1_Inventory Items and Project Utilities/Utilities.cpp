/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 10 Jul 2019
 */

#include "Utilities.h"

namespace sict {

	//default constructor 
	Utilities::Utilities() {}  

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string nextStr = str.substr(next_pos);  //from next_pos to the end of str
		size_t nextDilim = nextStr.find(delimiter);  // to fine the next delimiter of substr
		//std::string extractedtoken;

		if (nextDilim < std::string::npos) {
			nextStr = nextStr.substr(0, nextDilim);
			next_pos += nextDilim + 1;
			if (nextStr.size() > FW)
				FW = nextStr.size();
		}
		else if (nextDilim == std::string::npos) {
			nextStr = str.substr(next_pos);
			nextDilim = str.size() - 1; //returns the position that is beyond the end of the string
		}

		else { //reports an exception 
			throw std::string{ "No more tokens" };
		}
		return nextStr;
	}

	const char Utilities::getDelimiter() const {
		return delimiter;
	}


	size_t Utilities::getFieldWidth() const {
		return FW;
	}

	void Utilities::setDelimiter(const char d) {
		delimiter = d;
	}

	void Utilities::setFieldWidth(size_t w) {
		FW = w;
	}
}