
#if !defined(__SORT_H__)
#define __SORT_H__

#include <stdlib.h>

enum _FLAG{
	POS = 0,
	NEG
};

namespace Sort {
	template<typename T>			
		bool Swap(T* item1_, T* item2_);
	template<typename T>				//O(N^2)		Stable Alg.
		long long BubbleSort(T* t_, const size_t n, const _FLAG flag);
	template<typename T>				//O(N^2)		Unstable Alg.
		long long SelectSort(T* t_, const size_t n, const _FLAG flag);
	template<typename T>				//O(N^2)		Unstable Alg.
		long long InsertSort(T* t_, const size_t n, const _FLAG flag);
	template<typename T>				//O(NLogN)		Unstable Alg.
		long long HeapSort(T* t_, const size_t n, const _FLAG flag);
	template<typename T>				//O(NLogN)		Unstable Alg.
		long long QuickSort(T* t_, const size_t n, const _FLAG flag);
	template<typename T>
		long long ShellSort(T* t_, const size_t n, const _FLAG flag);
}
#include "BubbleSort.cpp"
#include "HeapSort.cpp"
#include "InsertSort.cpp"
#include "QuickSort-rec.cpp"
#include "SelectSort.cpp"
#include "ShellSort.cpp"
#include "Swap.cpp"
#endif // !defined(__SORT_H__)

