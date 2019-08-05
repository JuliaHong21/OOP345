/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 02 Aug 2019
 */

#include "Utilities.h"

namespace sict {
	char Utilities::delimiter = ' ';
	size_t Utilities::width = 0;
	
	Utilities::Utilities() {}   //default constructor 

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string beforeDelim = "";
		if (next_pos < str.size()) {
			size_t tmp = 0;
			tmp = str.find(delimiter, next_pos);
			if (tmp == -1) {
				beforeDelim = str.substr(next_pos, str.size() - next_pos);
				tmp = str.length();
			}
			else {
				beforeDelim = str.substr(next_pos, tmp-next_pos);
			}			
			
			if (next_pos == 0 && beforeDelim.length() > width) { // compares the size of the extracted token to the field width
				width = beforeDelim.length(); //increases the width if the size of the token > width
			}
			next_pos = tmp + 1;
		}
		else {
			next_pos++;
		}
		return beforeDelim;
	}

	const char Utilities::getDelimiter() const {
		return delimiter;
	}


	size_t Utilities::getFieldWidth() const {
		return width;
	}

	void Utilities::setDelimiter(const char d) {
		delimiter = d;
	}

	void Utilities::setFieldWidth(size_t w) {
		width = w;
	}
}