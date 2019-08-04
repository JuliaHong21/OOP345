/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-23 */

#ifndef _SICT_KVPAIR_H
#define _SICT_KVPAIR_H
#include <iostream>
#include <iomanip>

namespace sict {
	const int fWidth = 10;

	template<typename K, typename V>	
	class KVPair {
		K key;
		V value;
	public:
		//a default constructor
		KVPair() {}
		
		//a two-argument constructor 
		KVPair(const K& k, const V& v) : key(k), value(v) {}	

		//a templated query that inserts into the output stream os
		template<typename F>
		void display(std::ostream& os, F f) const {	
			KVPair tmp;
			if (key != tmp.key) {				
				os << std::setw(fWidth) << std::left << key << " : ";
				os << std::setw(fWidth) << std::right << value;
				os << std::setw(fWidth) << std::right << f(value) << std::endl;
			}			
		}
	};
}
#endif
