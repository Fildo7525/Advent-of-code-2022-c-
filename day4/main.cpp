#include "day4.h"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <numeric>
#include <utility>
#include <vector>
#include <iterator>

std::vector<std::string> split(const std::string &str, const std::string &delim);
void vprint(const std::vector<std::string> &v);

int main(int argc, char *argv[])
{
	std::fstream input("../input", std::ios::in);
	std::string line;
	int totalOverlaps = 0;

	while (std::getline(input, line)) {
		std::size_t temp;
		std::vector data = split(line,",");
		std::vector<std::string> e1 = split(data[0], "-");
		std::vector<std::string> e2 = split(data[1], "-");

		int start1 = std::stoi(e1[0]);
		int end1 = std::stoi(e1[1]);
		int start2 = std::stoi(e2[0]);
		int end2 = std::stoi(e2[1]);


		// std::printf("%d %d, %d %d\n", start1, end1, start2, end2);
		if ((start1 <= start2 && end1 >= end2) || (start1 >= start2 && end1 <= end2) ) {
			// std::cout << "OVERLAPING\n";
			totalOverlaps++;
		} else if ((end1 >= start2 && start1 <= start2) || (end2 >= start1 && start2 <= start1) ) {
		 	// std::cout << "OVERLAPING\n";
			totalOverlaps++;
		}
	}

	std::cout << "Overlaps: " << totalOverlaps << std::endl;
	return 0;
}

std::vector<std::string> split(const std::string &str, const std::string &delim)
{
	size_t pos_start = 0, pos_end, delim_len = delim.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = str.find (delim, pos_start)) != std::string::npos) {
		token = str.substr (pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back (token);
	}

	res.push_back(str.substr (pos_start));
	return res;
}

void vprint(const std::vector<std::string> &v)
{
	std::copy(v.cbegin(), v.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

