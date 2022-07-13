#include <iostream>
#include <vector>
#include <map>

//using history = std::map<int, bool>;
//
//bool CanAccumulate(int sum, const std::vector<int>& numbers, history& h)
//{
//	// solved
//	if (h.count(sum) == 1)
//	{
//		return h[sum];
//	}
//	
//	// base case
//	if (sum == 0)
//	{
//		return true;
//	}
//
//	if (sum < 0)
//	{
//		return false;
//	}
//
//	// recursive case
//	for (auto e : numbers)
//	{
//		int remain = sum - e;
//
//		if (CanAccumulate(remain, numbers, h) == true)
//		{
//			h[sum] = true;
//			return true;
//		}
//	}
//
//	h[sum] = false;
//	return false;
//}

using int_vector = std::vector<int>;

std::shared_ptr<int_vector> HowAccumulate(int sum, const int_vector& numbers)
{
	// base case
	if (sum == 0)
	{
		return std::make_shared<int_vector>();
	}

	if (sum < 0)
	{
		return nullptr;
	}

	// recursive case
	for (auto e : numbers)
	{
		int remain = sum - e;

		auto result = HowAccumulate(remain, numbers);

		if (result != nullptr)
		{
			result->push_back(e);
			return result;
		}
	}

	return nullptr;
}

void Print(std::shared_ptr<int_vector> result)
{
	std::cout << "{ ";

	if (result != nullptr)
	{
		for (auto e : *result)
		{
			std::cout << e << " ";
		}
	}

	std::cout << "}" << std::endl;
}

int main()
{
	//history h;
	//
	//std::cout << CanAccumulate(8, { 2, 3, 5 }, h) << std::endl;
	//h.clear();

	//std::cout << CanAccumulate(7, { 5, 3, 4, 7 }, h) << std::endl;
	//h.clear();

	//std::cout << CanAccumulate(720, { 10, 50, 100, 500 }, h) << std::endl;
	//h.clear();

	//std::cout << CanAccumulate(1000, { 7, 14 }, h) << std::endl;
	//h.clear();

	Print(HowAccumulate(8, { 2, 3, 5 }));
	Print(HowAccumulate(7, { 1, 4 }));
	Print(HowAccumulate(1000, { 7, 14 }));
}