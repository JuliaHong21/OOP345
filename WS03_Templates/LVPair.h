/*
 name: Youngeun Hong
 ID: 159100171
 Date: 2019-06-05 */


#ifndef _SICT_LVPAIR_H
#define _SICT_LVPAIR_H

#include<iostream>

namespace sict {
	template <typename L, typename V>
	class LVPair {
		L lb;
		V vl;

	public:
		LVPair() {			
		}

		LVPair(const L& label, const V& value) {
			lb = label;
			vl = value;
		}

		const L& getLabel() const {
			return lb;
		}

		const V& getValue() const {
			return vl;
		}

		virtual void display(std::ostream& os) const {
			os << lb << " : " << vl << std::endl;
		}		
	};


	template <typename L, typename N>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, N>& pair) {
		pair.display(os);
		return os;
	}	

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V initValue;
		static size_t minWidth;
	public:
		SummableLVPair() { }//default constructor 

		//an overloaded constructor that calls the base class 2-argument constructor
		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
			if(minWidth < label.size()) {
				minWidth = label.size();
			}			
		}		

		//a class function that returns the initial value for the summation of a set of LVPair objects of label type L. 
		static const V& getInitialValue() {
			return initValue;
		}		

		//returns in a V object the sum of the value of the current object and the partially accumulated sum.
		V sum(const L& label, const V& sum) const {
			return label == LVPair<L, V>::getLabel()? sum + LVPair<L, V>::getValue() : sum;
		}

		void display(std::ostream& os) const {
			os.setf(std::ios::left); //sets the std::ostream object to left-justified insertion
			os.width(minWidth); // a field width equal to that stored for objects of this class.			
			os << LVPair<L, V>::getLabel() << " : " << LVPair<L, V>::getValue() << std::endl;
			os.unsetf(std::ios::left);
			//LVPair<L, V>::display(os); //call display() from the parent class	

		}
	};
		

	//A templated declaration that initializes the field width class variable to 0.
	template <typename L, typename V>
	size_t SummableLVPair<L, V>::minWidth = 0U;  //initializes class valiable minWidth

	//template <typename L, typename V>
	//V SummableLVPair<L, V>::initValue = '\0';  //initializes class valiable initValue

	//A template specialization that initializes the starting value for an LVPair<std::string, int> type to 0.
	template<> 
	int SummableLVPair<std::string, int>::initValue = 0;

	//A template specialization that initializes the starting value for an LVPair<std::string, std::string> type to an empty string.
	template<> 
	std::string SummableLVPair<std::string, std::string>::initValue = "";
	
	//A template specialization of the sum() query for LVPair<std::string, std::string> types that inserts a single space between concatenating strings.
	template <>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string &label, const std::string &sum) const {
		return label == getLabel() ? sum + " " + getValue() : sum;
	}
}
#endif
