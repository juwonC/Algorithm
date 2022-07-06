#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5 };

	// Max Heap
	std::make_heap(v.begin(), v.end());

	for (auto& e : v)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;

	while (!v.empty())
	{
		std::cout << v.front() << " ";
		std::pop_heap(v.begin(), v.end());
		v.pop_back();
	}

	std::cout << std::endl;
}