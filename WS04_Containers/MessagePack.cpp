/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-12 */

 #include <iostream>
#include "MessagePack.h"

namespace sict {

	// A defualt constructor
	MessagePack::MessagePack() {
		msg = nullptr;
		msgNo = 0;
		missingMsgNo = 0;
	}

	// A two-argument constructor 
	MessagePack::MessagePack(Message** msgC, size_t n) {   //stores copies of objects that are not empty
		if (n > 0 && msgC != nullptr) {
			msgNo = n;
			msg = new Message[n];  // allocates dynamic memory	
			for (size_t i = 0; i < n; i++) {
				if (msgC[i] == nullptr || msgC[i]->empty()) {
					msg[i] = Message();
					missingMsgNo++;
				}
				else {
					msg[i] = Message(*msgC[i]);
				}
			}
		}
	}

	// A copy constructor
	MessagePack::MessagePack(const MessagePack& mpObj) {
		if (this != &mpObj) {
			msgNo = mpObj.msgNo;
			missingMsgNo = mpObj.missingMsgNo;
			msg = new Message [msgNo];
			for (size_t i = 0; i < msgNo; i++) {
				msg[i] = mpObj.msg[i];
			}
			delete[] mpObj.msg;
		}
	}

	// A move constructor
	MessagePack::MessagePack(MessagePack&& mpObj) noexcept {
		if (this != &mpObj) {
			msgNo = mpObj.msgNo;
			mpObj.msgNo = 0;
			missingMsgNo = mpObj.missingMsgNo;
			mpObj.missingMsgNo = 0;
			msg = new Message[msgNo];
			for (size_t i = 0; i < msgNo; i++){
				msg[i] = mpObj.msg[i];
			}
			mpObj.msg = nullptr;
		}
	}

	// displays the MessagePack objects within the container
	void MessagePack::display(std::ostream& os) const {
		for (size_t i = 0; i < msgNo; i++) {
			msg[i].display(os);
		}
	}

	size_t MessagePack::size() const {
		return msgNo - missingMsgNo;
	}

	//inserts into os the contents of the MessagePack object
	std::ostream& operator<<(std::ostream& os, MessagePack const& mp) {
		mp.display(os);
		return os;
	}

	//A destructor
	MessagePack::~MessagePack() {
		delete[] msg;
		msg = nullptr;
	}
}