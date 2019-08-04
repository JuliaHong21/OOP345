// Workshop 2 - Copy and Move Semantics
// Youngeun Hong(159100171)
// 29 May 2019
// SDD


#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H

#include <iostream>
#include <chrono>

namespace sict {
	const int max = 10;
	class Timekeeper {		
		int num_rd; //a.	The number records currently stored
		std::chrono::steady_clock::time_point st; //b.	The start time for the current event 
		std::chrono::steady_clock::time_point et; //c.	The end time for the current event 

		struct {
			const char* message; //string containing a message in a literal string
			const char* preUnit; //string containing the predefined units of time
			std::chrono::steady_clock::duration durOfRd;
		} record[max];

	public:
		Timekeeper(); 
		void start(); //a modifier that starts the stopwatch for an event
		void stop(); //a modifier that stops the stopwatch for an event
		void recordEvent(const char*); //a modifier that receives the address of a string that holds the description of the event 
		void report(std::ostream& os) const; //a query that receives a reference to an std::ostream object, inserts the title 
	};
}
#endif