// Workshop 2 - Copy and Move Semantics
// Youngeun Hong(159100171)
// 29 May 2019
// SDD


#include "Timekeeper.h"
#include <iomanip>

namespace sict {

	Timekeeper::Timekeeper() {
		num_rd = 0;
	}
	
	//a modifier that starts the stopwatch for an event
	void Timekeeper::start() {
		st = std::chrono::steady_clock::now();
	}

	//a modifier that stops the stopwatch for an event
	void Timekeeper::stop() {
		et = std::chrono::steady_clock::now();
	}

	//a modifier that receives the address of a string that holds the description of the event 
	void Timekeeper::recordEvent(const char* desOfEvent) { 
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(et - st);
		if (num_rd < max) {
			record[num_rd].message = desOfEvent;
			record[num_rd].preUnit = " seconds";
			record[num_rd].durOfRd = ms;
			num_rd++;
		}		
	}

	//a query that receives a reference to an std::ostream object, inserts the title 
	void Timekeeper::report(std::ostream& os) const {
		os << "\nExecution Times:\n";
		for (int i = 0; i < num_rd; i++)
			os << record[i].message << ' ' << std::setw(5)
			<< record[i].durOfRd.count() / 1000000
			<< record[i].preUnit
			<< std::endl;
	}		
}