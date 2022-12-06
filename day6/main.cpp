#include "day6.h"
#include <algorithm>
#include <iostream>

int main(int argc, char *argv[])
{
	std::fstream input("../input", std::ios::in);
	std::string line;
	std::getline(input, line);
	auto start = 0;
	auto end = 14;
	do
	{
		auto tmp = line.substr(start, 14);
		// std::cout << tmp << std::endl;
		std::sort(tmp.begin(), tmp.end());
		// std::cout << tmp << std::endl;
		tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
		// std::cout << tmp << std::endl << std::endl;
		if (tmp.size() == 14) {
			std::cout << "ANS: " << end << std::endl;
			return 0;
		}
		start++;
		end++;
	} while(true);
	std::cout << "Hello World!\n";
	return 0;
}

