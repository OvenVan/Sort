#ifndef __MERGSOT_CPP__
#define __MERGSOT_CPP__

#include "Sort.h"
#include <stdlib.h> 

template<typename T> 
long long Sort::MergeSort(T* t_, const size_t n, const _FLAG flag){
	
}

template<typename T>
long long Merge(T* t_, const size_t n, const _FLAG flag){
	T* p1 = t_;
	T* p2 = t_ + n;	
	T* pend1 = p2 - 1;
	T* pend2 = t_ + (n * 2 - 1);
	long long step = 0;
	T* temp_array = NULL;
	T* temp_n = 0;
	if ((1 == n) && (((flag == POS) && (*p1 > *p2)) || ((flag == NEG) && (*p1 < *p2)))){
		swap(p1, p2);
		++step;
		return step;
	}
	else if (1 == n){
		return 0;
	}

	temp_array = (T*)malloc(n * 2 * sizeof(T));

	while ((p1 < pend1) && (p2 < pend2)){
		if (((flag == POS) && (*p1 < *p2)) || (flag == NEG) && (*p1 > *p2)){
			*temp_array[temp_n] = *p1;
			++p1;
		}
		else{
			*temp_array[temp_n] = *p2;
			++p2;
		}
		++temp_n;
	}
	if (p1 == pend1){
		while (p2 < pend2){
			//
		}
	}
		
	free(temp_array);
}

#endif
