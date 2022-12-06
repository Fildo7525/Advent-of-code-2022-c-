#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <map>
#include <stack>

class day5
{
public:
	day5() = default;

};

struct step
{
	int move;
	int from;
	int to;
};

std::vector<char> readStack(std::string str);
step fillProcecureStep(const std::string &str);
void vprint(const std::vector<char> &v);
void sprint(const step &s);
std::vector<std::string> split(const std::string &str, const std::string &delim);
std::vector<std::stack<char>> populateStack(std::vector<std::vector<char>> &data);
void printTops(const std::vector<std::stack<char>> &data);

