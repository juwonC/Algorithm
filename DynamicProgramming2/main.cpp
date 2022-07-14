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
using history = std::map<int, std::shared_ptr<int_vector>>;

//std::shared_ptr<int_vector> HowAccumulate(int sum, const int_vector& numbers, std::shared_ptr<history> h)
//{
//	// solved
//	if (h->count(sum) == 1)
//	{
//		return (*h)[sum];
//	}
//	
//	// base case
//	if (sum == 0)
//	{
//		return std::make_shared<int_vector>();
//	}
//
//	if (sum < 0)
//	{
//		return nullptr;
//	}
//
//	// recursive case
//	for (auto e : numbers)
//	{
//		int remain = sum - e;
//		auto result = HowAccumulate(remain, numbers, h);
//
//		if (result != nullptr)
//		{
//			result->push_back(e);
//			(*h)[sum] = result;
//			return (*h)[sum];
//		}
//	}
//
//	(*h)[sum] = nullptr;
//	return nullptr;
//}

std::shared_ptr<int_vector> BestAccumulate(int sum, const int_vector& numbers, std::shared_ptr<history> h)
{
	// solved
	if (h->count(sum) == 1)
	{
		return (*h)[sum];
	}
	
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
	std::shared_ptr<int_vector> best;

	for (auto e : numbers)
	{
		int remain = sum - e;
		auto result = BestAccumulate(remain, numbers, h);

		if (result != nullptr)
		{
			std::shared_ptr<int_vector> v = std::make_shared<int_vector>();
			v->resize(result->size());
			std::copy(result->begin(), result->end(), v->begin());
			v->push_back(e);

			if (best == nullptr || v->size() < best->size())
			{
				best = v;
			}
		}
	}

	(*h)[sum] = best;
	return (*h)[sum];
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


	//Print(HowAccumulate(8, { 2, 3, 5 }, std::make_shared<history>()));
	//Print(HowAccumulate(7, { 1, 4 }, std::make_shared<history>()));
	//Print(HowAccumulate(1000, { 7, 14 }, std::make_shared<history>()));


	Print(BestAccumulate(8, { 2, 3, 5 }, std::make_shared<history>()));
	Print(BestAccumulate(7, { 5, 3, 4, 7 }, std::make_shared<history>()));
	Print(BestAccumulate(1000, { 7, 14 }, std::make_shared<history>()));
}