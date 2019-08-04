// Workshop 2 - Copy and Move Semantics
// Youngeun Hong(159100171)
// 29 May 2019
// SDD


#include "Text.h"
#include <fstream>

namespace sict {

	Text::Text() {		
		str = nullptr;
		numOfStr = 0;
	}

	//1-arg Constructor
	Text::Text(const char* nameOfFile) :Text() {
		std::string tmpstr;
		std::ifstream in;  //file to read
		in.open(nameOfFile);  //open the file
		
		if (in.is_open()) {
			while (std::getline(in,tmpstr, '\n')) {
				numOfStr++;
			}

			//in.clear();
			//in.seekg(0, std::ios::beg);
			str = new std::string[numOfStr]; //allocate memory dynamically  

			for (int i = 0; i < numOfStr; i++) 	{
				std::getline(in, str[i], '\n');
			}			
		}		
	}
	
	//Copy Constructor
	Text::Text(const Text& other) {
		str = nullptr;
		*this = other;
	}

	//Copy Assignment Operator
	Text& Text::operator=(const Text& other) {
		if (this != &other) {
			delete[] str;
			numOfStr = other.numOfStr;
			str = new std::string[numOfStr];
			for (int i = 0; i < numOfStr; i++) {
				str[i] = other.str[i];
			}
		}
		return *this;
	}

	//Move Constructor
	Text::Text(Text&& other) {		
		*this = std::move(other);
	}

	//Move Assignment Operator
	Text& Text::operator=(Text&& other) {
		if (this != &other) {
			delete[] str;
			numOfStr = other.numOfStr;
			str = other.str;
			other.numOfStr = 0;
			other.str = nullptr;
		}
		return *this;
	}

	//Destructor
	Text::~Text() {
		delete[] str;
	}

	size_t Text::size() const {
		return numOfStr;
	}

}