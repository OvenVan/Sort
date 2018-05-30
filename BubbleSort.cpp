#include "Sort.h"
#include <stdlib.h> 

template<typename T>
long long Sort::BubbleSort(T* t_, const size_t n, const _FLAG flag){
	size_t i, j;
	long long step = 0;
	T* t1 = NULL;
	T* t2 = NULL;
	for (i = n - 1; i > 0; --i){
		for (j = 0; j < i; ++j){
			t1 = t_ + j;
			t2 = t_ + j + 1;
			( ((*t1 > *t2) && (flag == 0)) || ((*t1 < *t2) && (flag == 1)) ) && 
				(Sort::Swap(t1, t2)) && (step += 1);
		}
	}
	return step;
}

template long long Sort::BubbleSort<int>(int*, const size_t, const _FLAG);
template long long Sort::BubbleSort<char>(char*, const size_t, const _FLAG);
template long long Sort::BubbleSort<double>(double*, const size_t, const _FLAG);
template long long Sort::BubbleSort<float>(float*, const size_t, const _FLAG);
