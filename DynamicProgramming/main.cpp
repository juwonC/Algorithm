#include <iostream>

int Fibonacci(int n)
{
	if (n <= 2)
	{
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	std::cout << Fibonacci(10);
}