/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-12 */

#include "Message.h"
#include "Notifications.h"

namespace sict { 

	// A defualt constructor
	Notifications::Notifications() {
		msg = nullptr;
	}

	// A one-argument constructor 
	Notifications::Notifications(int maxNoC) {
		if (maxNoC > 0) {
			msg = new const Message *[maxNoC];
			maxNo = maxNoC;
			curNo = 0;
		}
		else {
			msg = nullptr;
			maxNo = 0;
			curNo = 0;
		}
	}

	// A copy constructor
	Notifications::Notifications(const Notifications& ntObj) {
		if (this != &ntObj) {
			maxNo = ntObj.maxNo;
			curNo = ntObj.curNo;
			msg = new const Message *[maxNo];
			for (int i = 0; i < maxNo; i++)	{
				msg[i] = new Message(*ntObj.msg[i]);
			}
		}
	}

	// A move constructor
	Notifications::Notifications(Notifications&& ntObj) {
		if (this != &ntObj) {
			maxNo = ntObj.maxNo;
			ntObj.maxNo = 0;
			curNo = ntObj.curNo;
			ntObj.curNo = 0;
			msg = new const Message *[maxNo];
			for (int i = 0; i < maxNo; i++)	{
				msg[i] = ntObj.msg[i];
				ntObj.msg[i] = nullptr;
			}
		}
	}

	Notifications& Notifications::operator+=(const Message& msgC) {
		if (curNo < maxNo && !msgC.empty()) {
			msg[curNo++] = &msgC;
		}
		return *this;
	}

	Notifications& Notifications::operator-=(const Message& msgC) {
		int found = -1;
		for (int i = 0; i < curNo; i++) {
			if (msg[i] == &msgC) {
				found = i;
				//delete msg[i];
				msg[i] = nullptr;
				//break;
			}
		}
		if (found != -1) {
			for (int i = found; i < curNo - 1; i++) {
				msg[i] = msg[i + 1];
			}
			msg[--curNo] = nullptr;
		}
		return *this;
	}
	
	//destructor
	Notifications::~Notifications() {  
		delete[] msg;
		msg = nullptr;
	}
	
	//show the contents
	void Notifications::display(std::ostream& os) const {  
		for (int i = 0; i < curNo; i++) {
			msg[i]->display(os);
		}
	}

	size_t Notifications::size() const {
		return curNo;
	}

	std::ostream& operator<<(std::ostream& os, Notifications const& notifObj) {
		notifObj.display(os);
		return os;
	}
}