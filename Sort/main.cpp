#include <iostream>
#include "Sort.h"

int main()
{
	const int SIZE{ 5 };
	int array[SIZE]{ 8, 7, 2, 3, 1 };

	// SequentialSort(array, SIZE);
	// SelectionSort(array, SIZE);
	BubbleSort(array, SIZE);

	PrintArray(array, SIZE);
}