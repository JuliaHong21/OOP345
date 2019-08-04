/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-12 */


#ifndef _SICT_MESSAGE_H
#define _SICT_MESSAGE_H
#include <iostream>
#include <string>

namespace sict {
	class Message {
		std::string user;
		std::string reply;
		std::string tweet;
	public:
		Message(); //default constructor		
		Message(const std::string& str); //parses the string into three substrings
		bool empty() const;  //returns true if the current object is in a safe empty state
		void display(std::ostream& os) const;
	};

}
#endif