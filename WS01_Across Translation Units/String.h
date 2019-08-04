/*
Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
Date: 17 May 2019
Name: Youngeun Hong
Email: yhong38@myseneca.ca
ID: 159100171
Section: SDDL
*/

#ifndef SICT_STRING_H_
#define SICT_STRING_H_

#define MAX 3
#include<iostream>

namespace sict {
	class String {
		char* course;
		//char course[MAX + 1];
	public:
		String(const char* cstr);  //constructor
		void display(std::ostream& os) const;
		~String();
	};

	std::ostream& operator<<(std::ostream& os, const String& st);
}
#endif