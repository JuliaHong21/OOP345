// Workshop 5 - Functions
// w5.cpp
// Chris Szalwinski
// 2019/02/10

/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-23 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <exception>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"

using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		throw "Fail to open files";  //an exception
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	// check for command line errors
	if (argc != 3) {
		throw "The number of arguments is uncorrect";  //an exception
		exit(1);
	}

	// set for fixed, 2-decimal point output
	std::cout << std::fixed << std::setprecision(2);
	
	try {
		// process price list file
		KVList<KVPair<std::string, float>> priceList = createList<
			KVList<KVPair<std::string, float>>,
			KVPair<std::string, float>,
			std::string,
			float>
			(argv[1]);
		std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
		std::cout << "Description:      Price Price+Tax\n";
		priceList.display(std::cout, Taxable(HST));
	
		// process student grades list file	
		KVList<KVPair<int, float>> gradeList = createList<
			KVList<KVPair<int, float>>,
			KVPair<int, float>,
			int,
			float>
			(argv[2]);
		std::cout << "\nStudent List Letter Grades Included\n==================================\n";
		std::cout << "Student No :      Grade    Letter\n";

		gradeList.display(std::cout, [](float score) -> std::string {
			std::string letter;
			if (score <= 100 && score >= 90) letter = "A+";
			else if (score >= 80) letter = "A ";
			else if (score >= 75) letter = "B+";
			else if (score >= 70) letter = "B ";
			else if (score >= 65) letter = "C+";
			else if (score >= 60) letter = "C ";
			else if (score >= 55) letter = "D+";
			else if (score >= 50) letter = "D ";
			else if (score >= 0) letter = "F ";
			else throw "out of score";  //exception
			return letter;
		});
	}

	//exception handling 
	catch (const char* msg) {
		std::cout << msg << std::endl;
		std::exit(2);
	}

	catch (const std::exception& exc) {
		std::cerr << "Exception: " << exc.what() << std::endl;
		std::exit(3);
	}

	catch (...) {
		std::cout << "Error occurred" << std::endl;
		std::exit(4);
	}

	return 0;
}

