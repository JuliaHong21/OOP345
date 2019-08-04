/*
 name: Youngeun Hong
 ID: 159100171
 Email: yhong38@myseneca.ca
 Date: 2019-07-17
 */

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
// Workshop 8 - Smart Pointers
// Utilities.h
// Chris Szalwinski from Cornel Barna
// 2019/03/17

#include "List.h"
#include "Element.h"

namespace sict {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif