/*
 name: Youngeun Hong
 ID: 159100171
 Email: yhong38@myseneca.ca
 Date: 2019-07-17
 */

#ifndef SICT_LIST_H
#define SICT_LIST_H
// Workshop 8 - Smart Pointers
// List.h
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sict {
    template <typename T>
    class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(*new T(e));
            }
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		// TODO: Overload the += operator with a smart pointer
		//       as a second operand.
		void operator+=(const std::unique_ptr<T>& ptr) {
			list.push_back(*ptr);
		}

		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.
		void operator+=(const T* ptr) {
			list.push_back(*ptr);
		}

		void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
	};

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif