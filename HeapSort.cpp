#include "Sort.h"
#include <stdlib.h> 
long long step = 0;

size_t getNonLeafIndex(const size_t);

template<typename T>
bool HeapSwap(T* t_, const size_t n, const size_t index, size_t* spotLightIndex, const _FLAG flag);

template<typename T>
bool Heapify(T* t_, const size_t n, const size_t index, const _FLAG flag);

bool IsLeaf(const size_t n, const size_t index);

template<typename T>
long long Sort::HeapSort(T* t_, const size_t n, const _FLAG flag){		//n:1~n
	int i;

	size_t valiableN = n;						//valiableN:1~
	size_t nonLeafIndex = getNonLeafIndex(n);		//nonLeafIndex:1~
	T* tend = NULL;
	if (nonLeafIndex == 0) return true;
	for (i = nonLeafIndex; i > 0; --i){
		if(!Heapify(t_, valiableN, i, flag)) return -1;
	}
	for (valiableN = n - 1; valiableN >= 1; --valiableN){
		tend = t_ + valiableN;
		Sort::Swap(t_, tend);
		if(!Heapify(t_, valiableN, 1, flag)) return -1;
	}

	return step;
}

size_t getNonLeafIndex(const size_t n){
	size_t pow = 0;
	size_t num = 1;
	while (n > num){
		num <<= 1;
		pow++;
	};
	if (pow == 0)
		num = 2;	
	return ((num>>1) - 1);
}

template<typename T>
bool Heapify(T* t_, const size_t n, const size_t index, const _FLAG flag){		//all :1~
	bool swaped = false;
	size_t spotLightIndex = 0;	//1~
	swaped = HeapSwap(t_, n, index, &spotLightIndex, flag);
	(swaped) && (++step);
	if ((swaped) && (!IsLeaf(n, spotLightIndex))){
		return Heapify(t_, n, spotLightIndex, flag);
	}
	return true;
}

bool IsLeaf(const size_t n, const size_t index){
	return (index > getNonLeafIndex(n));
}

template<typename T>
bool HeapSwap(T* t_, const size_t n, const size_t index, size_t* spotLightIndex, const _FLAG flag){
	T* leftLeaf = NULL;
	T* rightLeaf = NULL;
	T* spotLight = t_ + index - 1; 
	*spotLightIndex = index;
	if (index > n)
		return false;
	if (n >= (index * 2) + 1){
		leftLeaf = t_ + (index * 2 - 1);
		rightLeaf = t_ + (index * 2);
		if (((flag == POS) && (*leftLeaf >= *rightLeaf) && (*spotLight < *leftLeaf)) ||
		   ((flag == NEG) && (*leftLeaf <= *rightLeaf) && (*spotLight > *leftLeaf)))	
		{
			Sort::Swap(spotLight, leftLeaf);
			*spotLightIndex = index * 2;
			return true;
		}
		else if (((flag == POS) && (*rightLeaf >= *leftLeaf) && (*spotLight < *rightLeaf)) ||
		   ((flag == NEG) && (*rightLeaf <= *leftLeaf) && (*spotLight > *rightLeaf)))	
		{
			Sort::Swap(spotLight, rightLeaf);
			*spotLightIndex = index * 2 + 1;
			return true;
		}
	}

	if (n == (index * 2)){
		leftLeaf = t_ + (index * 2 - 1);
		rightLeaf = NULL;
		if ( ((flag == POS) && (*spotLight < *leftLeaf)) || ((flag == NEG) && (*spotLight > *leftLeaf)) ){
			Sort::Swap(spotLight, leftLeaf);
			*spotLightIndex = index * 2;
			return true;
		}
	}
	if (n < (index * 2)){
		return false;
	}
	return false;

}
template long long Sort::HeapSort<int>(int*, const size_t, const _FLAG);
template long long Sort::HeapSort<char>(char*, const size_t, const _FLAG);
template long long Sort::HeapSort<double>(double*, const size_t, const _FLAG);
template long long Sort::HeapSort<float>(float*, const size_t, const _FLAG);

