#include "day3.h"
#include <algorithm>
#include <pstl/glue_algorithm_defs.h>
#include <string>

void rearange(std::string &s);
char findCommon(const std::string &lhs, const std::string &mhs, const std::string &rhs);
int getWeight(char c);

int main(int argc, char *argv[])
{
	std::fstream input("../input", std::ios::in);
	std::string firstElf;
	std::string secondElf;
	std::string thirdElf;
	int totalGain = 0;

	while (!input.eof()) {
		std::getline(input, firstElf);
		std::getline(input, secondElf);
		std::getline(input, thirdElf);

		rearange(firstElf);
		rearange(secondElf);
		rearange(thirdElf);

		char c = findCommon(firstElf, secondElf, thirdElf);
		// std::cout << "Char: " << c << " gain: " << getWeight(c) << std::endl;
		totalGain += getWeight(c);
	}
	std::cout << "Gain: " << totalGain << std::endl;
	return 0;
}

void rearange(std::string &s)
{
	std::sort(s.begin(), s.end());
	auto end = std::unique(s.begin(), s.end());
	s.erase(end-s.begin());
}

char findCommon(const std::string &lhs, const std::string &mhs, const std::string &rhs)
{
	for(char var : lhs) {
		if (rhs.find(var) != std::string::npos && mhs.find(var) != std::string::npos) {
			return var;
		}
	}
	return ' ';
}

int getWeight(char c)
{
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 1;
	} else if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 27;
	}
	return 0;
}

