#include <iostream>
#include <vector>

bool CanAccumulate(int sum, const std::vector<int>& numbers)
{
	// base case
	if (sum == 0)
	{
		return true;
	}

	if (sum < 0)
	{
		return false;
	}

	// recursive case
	for (auto e : numbers)
	{
		int remain = sum - e;

		if (CanAccumulate(remain, numbers) == true)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	std::cout << CanAccumulate(8, { 2, 3, 5 }) << std::endl;
	std::cout << CanAccumulate(7, { 5, 3, 4, 7 }) << std::endl;
	std::cout << CanAccumulate(720, { 10, 50, 100, 500 }) << std::endl;
	std::cout << CanAccumulate(1000, { 7, 14 }) << std::endl;
}