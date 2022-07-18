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

int CanGenerateCount(std::string target, const std::vector<std::string>& stringlist, history& h)
{
	// solved?
	if (h.count(target) == 1)
	{
		return h[target];
	}

	// base case
	if (target == "")
	{
		return 1;
	}

	// recursive case
	int count{};

	for (auto e : stringlist)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			count += (CanGenerate(subs, stringlist, h));
		}
	}

	h[target] = count;
	return count;
}

int main()
{
	history h;
	
	std::cout << CanGenerate("abcd", { "a", "b", "c", "d" }, h) << std::endl;
	h.clear();
	std::cout << CanGenerate("abcdef", { "ab", "abc", "cd", "def", "abcd" }, h) << std::endl;
	h.clear();
	std::cout << CanGenerate("HelloWorld", { "ab", "abc", "cd", "def", "abcd" }, h) << std::endl;
	h.clear();
	
	std::cout << CanGenerateCount("abcdef", { "ab", "abc", "cd", "def", "abcd", "ef"}, h) << std::endl;
	h.clear();
	std::cout << CanGenerateCount("hello", { "he", "h", "e", "llo", "hell" }, h) << std::endl;
	h.clear();
}