#include "day10.h"

std::vector<std::string> split(const std::string &toSplit, const std::string &delim)
{
	size_t pos_start = 0, pos_end, delim_len = delim.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = toSplit.find (delim, pos_start)) != std::string::npos) {
		token = toSplit.substr (pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back (token);
	}

	res.push_back(toSplit.substr (pos_start));
	return res;
}

