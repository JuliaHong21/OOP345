/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-23 */

#ifndef _SICT_KVLIST_H
#define _SICT_KVLIST_H
#include <iostream>

namespace sict {
	template<typename T>
	class KVList {
		T* list;
		int num;  //number of object
		int currentNum;  //current number of object

	public:
		//default constructor that places the object in a safe empty state
		KVList() {
			list = nullptr;
			num = 0;
			currentNum = 0;
		}

		//a single - argument constructor 
		KVList(int n) : KVList() {  // n =  the number of objects in the list
			if (n > 0) {
				list = new T[n];
				num = n;
				currentNum = 0;
			}
			else {
				throw "The number of elements received is not positive-valued"; //an exception
			}
		}

		//a move constructor
		KVList(KVList&& copy) {
			if (copy.list != nullptr) {
				num = copy.num;
				copy.num = 0;

				currentNum = copy.currentNum;
				copy.currentNum = 0;

				list = new T[num];
				for (int i = 0; i < num; i++) {
					list[i] = copy.list[i];
				}
				copy.list = nullptr;
			}
		}

		//a destructor
		~KVList() {
			delete[] list;
			list = nullptr;
		}

		//a subscripting operator that returns an unmodifiable reference to the i 
		const T& operator[](size_t i) const {
			if (i <= num) {
				return i < num ? list[i] : nullptr;
			}	 	
			else throw "out-of-bounds"; //exception
		}

		//a templated query that inserts into the output stream os
		template<typename F>
		void display(std::ostream& os, F f) const {
			if (num > 0 || list == nullptr) {
				for (int i = 0; i < num; i++) {
					list[i].display(os, f);
				}
			}
		}

		//a modifier that receives an unmodifiable reference to a T object t
		void push_back(const T& t) {
			if (currentNum < num) {  //if there is room in the list
				list[currentNum] = t;
				currentNum++;
			}
		}

		//disables copy and move assignment operationsand copy construction
		KVList(const KVList& src) = delete; //avoiding implicit copy constructor
		KVList& operator=(const KVList& src) = delete; //avoiding implicit copy assignment
		KVList& operator=(KVList&& src) = delete;  //avoiding implicit move assignment
		
	};
}
#endif