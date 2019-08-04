/*
Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
Date: 17 May 2019
Name: Youngeun Hong
Email: yhong38@myseneca.ca
ID: 159100171
Section: SDDL
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "String.h"
#include <cstring>

extern int INITIAL;
namespace sict {	
	
	//constructor
	String::String(const char* cstr) {	
		course = nullptr;
		if (cstr != nullptr) {
			course = new char[strlen(cstr) + 1];
			strncpy(course, cstr, strlen(cstr));
			//strncpy(course, cstr, MAX);
			//course[MAX] = '\0';
		} 
		else{
			course[0] = '\0';
		}
	}		

	void String::display(std::ostream& os) const{
		os << course;
	}

	String::~String() {
		
	}
	
	//helper non-friend operator
	std::ostream& operator<<(std::ostream& os, const String& st) {		
		static int numOfitem = INITIAL; //to store the current item number
				
		os << numOfitem << ": ";
		st.display(os);
		numOfitem++;

		return os;
	}
}