#include "Sort.h"
#include <stdlib.h>

template<typename T>
long long Sort::SelectSort(T* t_, const size_t n, const _FLAG flag){	//O(n^2)	Unstable Alg.
	long long step = 0;
	size_t i, j;
	T* t1 = NULL;		//the item that going to change
	T* t2 = NULL;		//the item to compare
	T* tSwapWitht1 = NULL;	
	for (i = 0; i < n; ++i){
		t1 = t_ + i;
		tSwapWitht1 = t1;
		for (j = i+1; j< n; ++j){
			t2 = t_ + j;
			((  ((flag == POS) && (*tSwapWitht1 > *t2)) ) || ( ((flag == NEG) && (*tSwapWitht1 < *t2)) ))
				&& (tSwapWitht1 = t2) && (++step);
		}	//for j
		(t1 != tSwapWitht1) &&
			(Sort::Swap(t1, tSwapWitht1)) && (++step) ; 
	}	//for i
	return step;
}


template long long Sort::SelectSort<int>(int*, const size_t, const _FLAG);
template long long Sort::SelectSort<char>(char*, const size_t, const _FLAG);
template long long Sort::SelectSort<double>(double*, const size_t, const _FLAG);
template long long Sort::SelectSort<float>(float*, const size_t, const _FLAG);

