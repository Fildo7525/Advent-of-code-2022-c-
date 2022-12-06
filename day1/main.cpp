#include "day1.h"
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <iterator>

int main(int argc, char *argv[])
{
	std::fstream file ("../input", std::ios::in);
	std::string line;
	std::vector<long> maxs(3);
	long temp = 0;

	while(std::getline(file, line)) {
		// std::cout << "line: " << line << std::endl;
		if (line == "") {
			maxs.push_back(temp);
			temp = 0;
			continue;
		}
		temp += std::stol(line);
	}
	maxs.push_back(temp);
	std::sort(maxs.begin(), maxs.end(), std::greater<long>());
	std::copy(maxs.cbegin(), maxs.cend(), std::ostream_iterator<long>(std::cout, " "));
	std::accumulate(maxs.begin(), maxs.begin()+3, 0);

	std::cout << "\nMax: " << std::accumulate(maxs.begin(), maxs.begin()+3, 0) << "\n";
	return 0;
}

