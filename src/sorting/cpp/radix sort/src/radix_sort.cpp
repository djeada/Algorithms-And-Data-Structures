#include <algorithm>
#include "radix_sort.h"
const unsigned int RANGE = 255;

template <typename T>void RadixSortLSD(int *a, int arraySize)
void radix_sort(int *a, int arraySize)
{
	int i, bucket[MAX], maxVal = 0, digitPosition =1 ;
	for(i = 0; i < arraySize; i++) {
		if(a[i] > maxVal) maxVal = a[i];
	}

	int pass = 1;  // used to show the progress
	/* maxVal: this variable decide the while-loop count 
	           if maxVal is 3 digits, then we loop through 3 times */
	while(maxVal/digitPosition > 0) {
		/* reset counter */
		int digitCount[10] = {0};

		/* count pos-th digits (keys) */
		for(i = 0; i < arraySize; i++)
			digitCount[a[i]/digitPosition%10]++;

		/* accumulated count */
		for(i = 1; i < 10; i++)
			digitCount[i] += digitCount[i-1];

		/* To keep the order, start from back side */
		for(i = arraySize - 1; i >= 0; i--)
			bucket[--digitCount[a[i]/digitPosition%10]] = a[i];

		/* rearrange the original array using elements in the bucket */
		for(i = 0; i < arraySize; i++)
			a[i] = bucket[i];

		/* at this point, a array is sorted by digitPosition-th digit */
		cout << "pass #" << pass++ << ": ";
		print(a,arraySize);

		/* move up the digit position */
		digitPosition *= 10;
	}   
 }
 

template void radix_sort<int>(std::vector<int> &arr);
template void radix_sort<float>(std::vector<float> &arr);
template void radix_sort<double>(std::vector<double> &arr);
template void radix_sort<char>(std::vector<char> &arr);
