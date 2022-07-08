#include <iostream>
#include <map>

using history = std::map<int, int64_t>;

int64_t Fibonacci(int n, history& h)
{
	if (h.count(n) == 1)
	{
		return h[n];
	}
	
	// base case
	if (n <= 2)
	{
		return 1;
	}

	// recursive case
	h[n] = Fibonacci(n - 1, h) + Fibonacci(n - 2, h);
	return h[n];
}

int main()
{
	history h;
	
	std::cout << Fibonacci(50, h);
}