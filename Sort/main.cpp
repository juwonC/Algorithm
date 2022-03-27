#include <iostream>
#include "Sort.h"

int main()
{
	const int SIZE{ 5 };
	int array[SIZE]{ 8, 7, 2, 3, 1 };
	int tempArray[SIZE]{};

	// SequentialSort(array, SIZE);
	// SelectionSort(array, SIZE);
	// BubbleSort(array, SIZE);
	// InsertionSort(array, SIZE);
	MergeSort(array, 0, SIZE - 1, tempArray);

	PrintArray(array, SIZE);
}