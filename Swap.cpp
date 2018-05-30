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

template bool Sort::Swap<int>(int*, int*);
template bool Sort::Swap<char>(char*, char*);
template bool Sort::Swap<double>(double*, double*);
template bool Sort::Swap<float>(float*, float*);

