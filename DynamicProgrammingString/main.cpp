#include <iostream>
#include <vector>
#include <string>

bool CanGenerate(std::string target, const std::vector<std::string>& stringList)
{
	// base case
	if (target == "")
	{
		return true;
	}

	// recursive case
	for (auto e : stringList)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());

			if (CanGenerate(subs, stringList))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	std::cout << CanGenerate("abcd", { "a", "b", "c", "d" }) << std::endl;
	std::cout << CanGenerate("abcdef", { "ab", "abc", "cd", "def", "abcd" }) << std::endl;
	std::cout << CanGenerate("HelloWorld", { "ab", "abc", "cd", "def", "abcd" }) << std::endl;
}