#include "Sort.h" 
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <time.h>
#include <algorithm>
#define MAX 10000

using namespace std;


int main(int argc, char** argv) {

 	long long st;
	timeval s,e;
	double usetime;
	int x1[MAX],x2[MAX], x3[MAX], x4[MAX], x5[MAX], x6[MAX];
	srand((int)time(0));
	for (int i = 0; i<MAX; i++){
		int ri = i;
		ri = 1 + (int)(500.0 * rand()/(RAND_MAX + 1.0));
/*
		if (i == 3000)
			ri = 8000;
		if (i == 8000)
			ri = 3000;
*/
		x1[i] = ri;
		x2[i] = ri;
		x3[i] = ri;
		x4[i] = ri;
		x5[i] = ri;
		x6[i] = ri;

	}
/*
	Sort::HeapSort(x1,MAX,NEG);
	Sort::HeapSort(x2,MAX,NEG);
	Sort::HeapSort(x3,MAX,NEG);
	Sort::HeapSort(x4,MAX,NEG);
	Sort::HeapSort(x5,MAX,NEG);
*/
	cout<<"Standard Sort:\n";
	st = 0;
	gettimeofday(&s, 0);
	sort(x6, x6 + MAX);
	gettimeofday(&e, 0);
	usetime = 1000000 * (e.tv_sec - s.tv_sec) + e.tv_usec - s.tv_usec;
	usetime /= 1000;
	cout<<st<<"step, "<<usetime<<"ms. "<<endl;
	cout<<endl<<endl;


	cout<<"SelectSort:\n";
	//st = Sort::BubbleSort(x,MAX,NEG); 
	gettimeofday(&s, 0);
	st = Sort::SelectSort(x1,MAX,POS);
	gettimeofday(&e, 0);
	usetime = 1000000 * (e.tv_sec - s.tv_sec) + e.tv_usec - s.tv_usec;
	usetime /= 1000;
	cout<<st<<"step, "<<usetime<<"ms. "<<endl;
	cout<<endl<<endl;

	cout<<"HeapSort:\n";
	//st = Sort::BubbleSort(x2,MAX,NEG); 
	gettimeofday(&s, 0);
	st = Sort::HeapSort(x2, MAX, POS);
	gettimeofday(&e, 0);
	usetime = 1000000 * (e.tv_sec - s.tv_sec) + e.tv_usec - s.tv_usec;
	usetime /= 1000;
	cout<<st<<"step, "<<usetime<<"ms. "<<endl;
	cout<<endl<<endl;

/*
	cout<<"BubbleSort:\n";
	//st = Sort::BubbleSort(x3,MAX,NEG); 
	gettimeofday(&s, 0);
	st = Sort::BubbleSort(x3, MAX, POS);
	gettimeofday(&e, 0);
	usetime = 1000000 * (e.tv_sec - s.tv_sec) + e.tv_usec - s.tv_usec;
	usetime /= 1000;
	cout<<st<<"step, "<<usetime<<"ms. "<<endl;
	cout<<endl<<endl;
*/

	cout<<"Insert Sort:\n";
	//st = Sort::BubbleSort(x,MAX,NEG); 
	gettimeofday(&s, 0);
	st = Sort::InsertSort(x4, MAX, POS);
	gettimeofday(&e, 0);
	usetime = 1000000 * (e.tv_sec - s.tv_sec) + e.tv_usec - s.tv_usec;
	usetime /= 1000;
	cout<<st<<"step, "<<usetime<<"ms. "<<endl;
	cout<<endl<<endl;

	cout<<"Quick Sort:\n";
	//st = Sort::BubbleSort(x,MAX,NEG); 
	gettimeofday(&s, 0);
	st = Sort::QuickSort(x5, MAX, POS);
	gettimeofday(&e, 0);
	usetime = 1000000 * (e.tv_sec - s.tv_sec) + e.tv_usec - s.tv_usec;
	usetime /= 1000;
	cout<<st<<"step, "<<usetime<<"ms. "<<endl;
	cout<<endl<<endl;
	
	return 0;

}
