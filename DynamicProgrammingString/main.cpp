#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

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

using result = std::list<std::list<std::string>>;
using History = std::map<std::string, result>;

result FindGenerate(std::string target, const std::vector<std::string>& stringList, History& h)
{
	// solved
	if (h.count(target) == 1)
	{
		return h[target];
	}
	
	// base case
	if (target == "")
	{
		return result{ {} };
	}

	// recursive case
	result r;

	for (auto e : stringList)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			auto ret = FindGenerate(subs, stringList, h);

			for (auto e2 : ret)
			{
				e2.push_front(e);
				r.push_front(e2);
			}
		}
	}
	h[target] = r;
	return r;
}

void Print(const result& r)
{
	std::cout << "{" << std::endl;

	for (auto e1 : r)
	{
		std::cout << "\t{ ";

		for (auto e2 : e1)
		{
			std::cout << e2 << ", ";
		}
		std::cout << "}, " << std::endl;
	}

	std::cout << "}" << std::endl;
}

int main()
{
	history h;
	History h1;

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

	Print(FindGenerate("abcdef", { "ab", "abc", "cd", "def", "abcd", "ef" }, h1));
}