#include <iostream>
#include <vector>
#include <string>
#include <map>

using history = std::map<std::string, bool>;

bool CanGenerate(std::string target, const std::vector<std::string>& stringList, history& h)
{
	// solved
	if (h.count(target) == 1)
	{
		return h[target];
	}

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

			if (CanGenerate(subs, stringList, h))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	history h;
	
	std::cout << CanGenerate("abcd", { "a", "b", "c", "d" }, h) << std::endl;
	h.clear();
	std::cout << CanGenerate("abcdef", { "ab", "abc", "cd", "def", "abcd" }, h) << std::endl;
	h.clear();
	std::cout << CanGenerate("HelloWorld", { "ab", "abc", "cd", "def", "abcd" }, h) << std::endl;
}