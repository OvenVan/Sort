#ifndef __QCKSOT_CPP__
#define __QCKSOT_CPP__
#include "Sort.h"
#include <stdlib.h> 


template<typename T>
long long Separation(T* t_, T* right, const _FLAG flag, size_t* separa);

template<typename T>
long long Sort::QuickSort(T* t_, const size_t n, const _FLAG flag){
	long long step = 0;
	size_t pos = 0;
	T* right = t_ + (n - 1);
	step += Separation(t_, right, flag, &pos);
	if (pos != 0){
		size_t sub_n = pos - 1;
		step += QuickSort(t_, sub_n, flag);
		sub_n = n - 1 - sub_n;
		step += QuickSort(t_ + pos, sub_n, flag);
		return step;
	}
	else{
		return step;
	}

}

template<typename T>
long long Separation(T* t_, T* right, const _FLAG flag, size_t* separa){
	T temp, temp1, temp2;
	T* left = t_ + 1;
	*separa = 0;
	long long step = 0;
	size_t n = right - t_ + 1;
	if (n <= 1){
		return 0;
	}
	if ((n == 2) && (((flag == POS) && (*t_ > *right)) || ((flag == NEG) && (*t_ < *right)))){
		Sort::Swap(t_, right);
		++step;
		return step;
	}
	if (n == 2)
		return step;

	temp = *t_;
	temp1 = *right;
	temp2 = *t_ + (1 + n) / 2 - 1;

	if ((temp1 < temp2)	&& (temp1 > temp))
		temp = temp1;
	if ((temp2 < temp1) && (temp2 > temp))
		temp = temp2;

	while (left < right){
		while ( ((flag == POS) && (*left < temp)) || ((flag == NEG) && (*left > temp)) ){
			if (left < right)
				++left;
			else
				break;
		}
		while ( ((flag == POS) && (*right >= temp)) || ((flag == NEG) && (*right <= temp)) ){
			if (left < right)
				--right;
			else
			break;
		}
		if (left != right){
			Sort::Swap(left, right);
			step++;
		}
		else{
			Sort::Swap(t_, left - 1);
			step++;
		}		
	}
	*separa = left - t_;
	return step;
}
#endif
