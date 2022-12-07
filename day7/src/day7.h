#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <memory>
#include <map>

std::vector<std::string> split(const std::string &toSplit, const std::string &delim);

class day7 : public std::enable_shared_from_this<day7>
{
public:
	day7() = default;
	day7(std::string name, std::shared_ptr<day7> parent);

	void addNode(std::string node);
	void addLeaf(std::string node, long size);

	std::shared_ptr<day7> goToParent();
	std::shared_ptr<day7> goTo(const std::string &dir);

	std::vector<std::shared_ptr<day7>> m_nodes;
	std::map<std::string, long> m_files;
	std::shared_ptr<day7> m_parent;
	std::string m_dirName;
	long m_size;
};

