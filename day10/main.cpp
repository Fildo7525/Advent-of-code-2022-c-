#include "day10.h"
#include <algorithm>
#include <iostream>
#include <iterator>

std::vector<std::string> screen;

void checkCycle(int cycle, long spritePos);

int main(int argc, char *argv[])
{
	for (size_t i = 0; i < 6; i++) {
		screen.push_back(std::string(40, '.'));
	}

	std::fstream input("../input", std::ios::in);
	std::string line;
	long spritePosition = 1;
	int cycle = 0;

	while (std::getline(input, line)) {
		cycle++;
		checkCycle(cycle, spritePosition);
		auto data = split(line, " ");
		if (data[0] == "addx") {
			int modificiation = std::stoi(data[1]);
			cycle++;
			checkCycle(cycle, spritePosition);
		}
		// noop continues
	}
	std::copy(screen.cbegin(), screen.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

	return 0;
}

void checkCycle(int cycle, long spritePosition)
{
	cycle--;
	if (spritePosition == cycle%40 || spritePosition == (cycle%40) - 1 || spritePosition == (cycle%40)+1) {
		screen[cycle/40][cycle%40] = '#';
	}
}

