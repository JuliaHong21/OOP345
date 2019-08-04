/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-12 */

#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

namespace sict {

	class Message;
	class Notifications {  //manages an aggregation of Message objects
		const Message** msg = nullptr;  //a pointer to a dynamically allocated array of addresses
		int maxNo = 0;
		int curNo = 0;
		char* a;
	public:
		Notifications();  // A defualt constructor
		Notifications(int maxNoC);  // A one-argument constructor 
		Notifications(const Notifications& mpObj);  // A copy constructor
		Notifications(Notifications&& mpObj);  // A move constructor
		Notifications& operator+=(const Message& msgC);
		Notifications& operator-=(const Message& msgC);
		~Notifications();  //A destructor
		void display(std::ostream& os) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream& os, Notifications const& notifObj);
}

#endif