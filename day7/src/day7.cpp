#include "day7.h"
#include <memory>

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

day7::day7(std::string name, std::shared_ptr<day7> parent)
	: m_dirName(name)
	, m_parent(parent)
	, m_size(0)
{
}

void day7::addNode(std::string node)
{
	m_nodes.push_back(std::make_shared<day7>(node, this->shared_from_this()));
}

void day7::addLeaf(std::string node, long size)
{
	m_files.insert({node, size});
}

std::shared_ptr<day7> day7::goToParent()
{
	return m_parent;
}

std::shared_ptr<day7> day7::goTo(const std::string &dir)
{
	for (auto i = m_nodes.begin(); i < m_nodes.end(); i++) {
		if ((*i)->m_dirName == dir) {
			return *i;
		}
	}
	return nullptr;
}

