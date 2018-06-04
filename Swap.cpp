#ifndef __SWPSOT_CPP__
#define __SWPSOT_CPP__
#include "Sort.h"
#include <iostream>
using namespace std;

template<typename T>
bool Sort::Swap(T* item1_, T* item2_){
	T temp = *item1_;
	*item1_ = *item2_;
	*item2_ = temp;
	return true;
}

#endif
