#include <iostream>
#include <map>
#include <string>

//using history = std::map<int, int64_t>;
//
//int64_t Fibonacci(int n, history& h)
//{
//	if (h.count(n) == 1)
//	{
//		return h[n];
//	}
//	
//	// base case
//	if (n <= 2)
//	{
//		return 1;
//	}
//
//	// recursive case
//	h[n] = Fibonacci(n - 1, h) + Fibonacci(n - 2, h);
//	return h[n];
//}

using history = std::map<std::string, int>;

int FindWays(int m, int n, history& h)
{
	const std::string key = std::to_string(m) + "," + std::to_string(n);
	const std::string rKey = std::to_string(n) + "," + std::to_string(m);

	// solved?
	if (h.count(key) == 1)
	{
		return h[key];
	}

	if (h.count(rKey) == 1)
	{
		return h[rKey];
	}

	// base case
	if (m == 0 || n == 0)
	{
		return 0;
	}

	if (m == 1 || n == 1)
	{
		return 1;
	}

	// recursive case
	h[key] = FindWays(m - 1, n, h) + FindWays(m, n - 1, h);
	return h[key];
}

int main()
{
	history h;
	
	//std::cout << Fibonacci(50, h) << std::endl;
	std::cout << FindWays(20, 20, h) << std::endl;
}