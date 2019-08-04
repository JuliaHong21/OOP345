/*
 name: Youngeun Hong
 ID: 159100171
 Email: yhong38@myseneca.ca
 Date: 2019-06-27 */

#include "Sale.h"
#include <fstream>
#include <iomanip>

extern int FW;

namespace sict{
	Sale::Sale(const char* fName) { //A single argument constructor 
		std::ifstream rfile; //read file
		rfile.open(fName);

		if (rfile.is_open()) {  //if the file is opened
			std::string buffer;
			int count = 0;

			while (std::getline(rfile, buffer)) { count++; }
			
			rfile.clear();			
			rfile.seekg(0, std::ios::beg);

			for (int i = 0; i < count; i++) 
				pfile.push_back(readRecord(rfile));

			rfile.close();
		}
		else { throw "Cannot be opened"; }
	}

	void Sale::display(std::ostream & os) const	{
		os << "\nProduct No" << std::setw(FW) << "Cost" 
		   << ' ' << "Taxable" << std::endl;

		double total = 0.0 ;
		for (auto& i : pfile) {
			os << *i;			
			total += i->price();
		}
		os << std::fixed << std::setprecision(2) << std::setw(FW) << "Total" 
		   << std::setw(FW) << total << std::endl;
	}
}
