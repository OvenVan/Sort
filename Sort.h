
#if !defined(__SORT_H__)
#define __SORT_H__

#include <stdlib.h>

enum _FLAG{
	POS = 0,
	NEG
};

class Sort {
public:
	template<typename T>			
		static bool Swap(T* item1_, T* item2_);
	template<typename T>				//O(N^2)		Stable Alg.
		static long long BubbleSort(T* t_, const size_t n, const _FLAG flag);
	template<typename T>				//O(N^2)		Unstable Alg.
		static long long SelectSort(T* t_, const size_t n, const _FLAG flag);
	template<typename T>				//O(N^2)		Unstable Alg.
		static long long InsertSort(T* t_, const size_t n, const _FLAG flag);
	template<typename T>				//O(NLogN)		Unstable Alg.
		static long long HeapSort(T* t_, const size_t n, const _FLAG flag);
	template<typename T>				//O(NLogN)		Unstable Alg.
		static long long QuickSort(T* t_, const size_t n, const _FLAG flag);
};


#endif // !defined(__SORT_H__)

