/*
Name: Youngeun Hong
ID: 159100171
Email: yhong38@myseneca.ca
Date: 02 Aug 2019
 */

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include <string> 
#include <iostream>

namespace sict {

	class Utilities	{
		static size_t width;  //field width 		
	public:
		static char delimiter;
		Utilities(); //default constructor 
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t w);
	};
}
#endif 