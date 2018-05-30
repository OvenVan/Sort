#include "Sort.h"
#include <stdlib.h> 

template<typename T>
long long Sort::InsertSort(T* t_, const size_t n, const _FLAG flag){
	size_t i;
	T* t1 = NULL;		//compared item
	T* t2 = NULL;
	T temp;
	long long step = 0;
	for (i = 1; i < n; i++){
		t1 = (t_ + i);
		t2 = (t_ + i - 1);
		if (((flag == POS) && ( *t1 >= *t2)) || ((flag == NEG) && (*t1 <= *t2))){
			continue;
		}		//t2 free
		temp = *t1;
		while (((*t2 > temp) && (flag == POS)) || ((*t2 < temp) && (flag == NEG))){
			*(t2 + 1) = *t2;
			step++;
			if (t2 == t_){
				step++;
				break;
			}
			--t2;
		}
		if ((t2 == t_)&& ( ((flag == POS)&&(*t_ > temp))||((flag == NEG)&&(*t_ < temp)) )){
			*t2 = temp;
		}
		else{
			*(t2 + 1) = temp;
		}
	}	
	return step;
}


template long long Sort::InsertSort<int>(int*, const size_t, const _FLAG);
template long long Sort::InsertSort<char>(char*, const size_t, const _FLAG);
template long long Sort::InsertSort<double>(double*, const size_t, const _FLAG);
template long long Sort::InsertSort<float>(float*, const size_t, const _FLAG);

