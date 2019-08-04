/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-12 */

#include "Message.h"


namespace sict {
	Message::Message() { //default constructor		
		user = "";
		reply = "";
		tweet = "";
	}

	Message::Message(const std::string& str) { //parses the string into three substrings			
		std::string nextStr;
		size_t end = str.find(' ');
		user = str.substr(0, end); // find user
		
		if (str.size() == user.size()){ // if there is no text in the message		
			*this = Message();
		}
		else { 
			nextStr = str.substr(end + 1); 
			if (nextStr.find('@') != std::string::npos) { // if there is a reply
				end = nextStr.find(' ');
				reply = nextStr.substr(1, end - 1); // after @				
				nextStr = nextStr.substr(end + 1); // the rest of string to the end
			}
			tweet = nextStr;
		}		
	}
	
	bool Message::empty() const {  //returns true if the current object is in a safe empty state
		return user == "";
	}
	
	void Message::display(std::ostream& os) const {
		if (!this->empty()) {
			std::cout << ">User  : " << user << std::endl;

			if (reply != "") {
				std::cout << " Reply : " << reply << std::endl;
			}

			std::cout << " Tweet : " << tweet << '\r' << std::endl;
		}
	}
}
