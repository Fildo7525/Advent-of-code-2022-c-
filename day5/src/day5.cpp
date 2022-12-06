#include "day5.h"

std::vector<char> readStack(std::string str)
{
	std::vector<char> out((str.size()+1)/4);
	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '[') {
			out[i/4] = str[i+1];
			i++;
		}
	}
	return out;
}

void vprint(const std::vector<char> &v)
{
	for(auto var : v) {
		if (var == 0) {
			std::cout << 0;
		}
		else {
			std::cout << var;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}

step fillProcecureStep(const std::string &str)
{
	step s;
	auto splited = split(str, " ");
	s.move = std::stoi(splited[1]);
	s.from = std::stoi(splited[3]);
	s.to = std::stoi(splited[5]);
	return s;
}

void sprint(const step &s)
{
	std::cout << "move: " << s.move << " from: " << s.from << " to: " << s.to << std::endl;
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

std::vector<std::stack<char>> populateStack(std::vector<std::vector<char>> &data)
{
	std::vector<std::stack<char>> out(data[0].size());
	for (auto i = data.crbegin(); i != data.crend(); i++) {
		for (auto j = 0; j < i->size(); j++) {
			if (i->at(j) != 0) {
				out[j].push(i->at(j));
			}
		}
	}
	return out;
}

void printTops(const std::vector<std::stack<char>> &data)
{
	for(auto s : data) {
		if (!s.empty()) {
			std::cout << s.top() << " ";
		}
	}
	std::cout << std::endl;
}


