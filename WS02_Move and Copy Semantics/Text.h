// Workshop 2 - Copy and Move Semantics
// Youngeun Hong(159100171)
// 29 May 2019
// SDD


#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include <iostream>
#include <string>

namespace sict {
	class Text {
		std::string* str;
		int numOfStr;
	public:
		Text();
		Text(const char*);
		Text(const Text&);		
		Text& operator=(const Text&);
		Text(Text&&); //move-constructor
		Text& operator=(Text&&); //move-assignment operatior
		~Text();
		size_t size() const;
	};
}
#endif