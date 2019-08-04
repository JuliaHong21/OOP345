/*
Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
Date: 17 May 2019
Name: Youngeun Hong
Email: yhong38@myseneca.ca
ID: 159100171
Section: SDDL
*/

#include "process.h"
#include <iostream>
using namespace sict;
int INITIAL = 3;

int main(int argc, char *argv[]){	
	int retValue = 0;  //return value

	//echoes the set of arguments to standard output 
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	//inserts the error message 
	if (argc == 1) {  //if the user has not entered any string
		std::cout << "***Insufficient number of arguments***" << std::endl; //inserts the error message 
		retValue = 1;
	}
	else if (argc > 1) {
		for (int i = 1; i < argc; i++) {  //calls the process function for each string
			process(argv[i]);
			retValue = 0;
		}
	}

	return retValue;
}
