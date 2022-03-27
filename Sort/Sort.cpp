#include <iostream>
#include "Sort.h"

void PrintArray(int input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

void Swap(int& value1, int& value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

// Sequentail Srot
// Time Complexity : O(n^2)
// Space Complexity : O(n)
void SequentialSort(int input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}
}

// Selection Sort
// Time Complexity : O(n^2)
// Space Complexity : O(n)
void SelectionSort(int input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int minIndex = i;
		for (int j = i; j < size; ++j)
		{
			if (input[minIndex] > input[j])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			Swap(input[i], input[minIndex]);
		}
	}
}

// Bubble Sort
// Time Complexity : O(n^2)
// Space Complexity : O(n)

void BubbleSort(int input[], int size)
{
	for (int phase = 0; phase < size - 1; ++phase)
	{
		for (int left = 0; left < size - 1 - phase; ++left)
		{
			if (input[left] > input[left + 1])
			{
				Swap(input[left], input[left + 1]);
			}
		}
	}
}