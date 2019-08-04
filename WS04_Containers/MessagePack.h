/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-12 */

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include "Message.h"
namespace sict {
	
	class MessagePack {  //manages a composition of Message objects
		Message* msg = nullptr; //address of an array of Message objects 
		size_t msgNo = 0; // the number of elements in an array of Message objects 
		size_t missingMsgNo = 0;  //the number of elements that are empty
	public:
		MessagePack();  // A defualt constructor
		MessagePack(Message** msgC, size_t n);  // A two-argument constructor 
		MessagePack(const MessagePack& mpObj);  // A copy constructor
		MessagePack(MessagePack&& mpObj) noexcept; // A move constructor
		~MessagePack(); //A destructor
		void display(std::ostream& os) const;  
		size_t size() const;		
	};
	std::ostream& operator<<(std::ostream & os, MessagePack const& mp);  //inserts into os the contents of the MessagePack object
}

#endif