#include "day7.h"
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

// high 34'474'241

std::shared_ptr<day7> loadTree();
void calculateSizes(std::shared_ptr<day7> tree);
long pt1(std::shared_ptr<day7> node);

long totalSize = 0;

int main(int argc, char *argv[])
{
	auto tree = loadTree();
	calculateSizes(tree);
	// pt1(tree);
	return 0;
}

std::shared_ptr<day7> loadTree()
{
	std::fstream input("../input", std::ios::in);
	std::string line;
	std::shared_ptr<day7> actual(new day7("/", nullptr));
	auto root = actual;

	std::getline(input, line);
	std::getline(input, line);

	while (!input.eof()) {
		// std::cout << "Line: " << line << std::endl;
		if (line.find("$") != std::string::npos) {
			if (line.find("cd ") != std::string::npos) {
				// std::cout << "CD: " << line << std::endl;
				auto words = split(line, " ");
				if (words[2] == "..") {
					actual = actual->goToParent();
				} else {
					actual = actual->goTo(words[2]);
				}
				std::getline(input, line);
			} else if (line.find("ls") != std::string::npos) {
				do {
					std::getline(input, line);
					// std::cout << "LS: " << line << std::endl;
					if (input.eof()) {
						return root;;
					}
					if (line.find('$') != std::string::npos) {
						break;
					}
					if (line.find("dir") != std::string::npos) {
						auto words = split(line, " ");
						// std::cout << "Adding dir: " << line << std::endl;
						actual->addNode(words[1]);
					} else {
						auto words = split(line, " ");
						// std::cout << "Adding leaf: " << words[0] << words[1] << std::endl;
						actual->addLeaf(words[1], std::stol(words[0]));
					}
				} while(true);
			}
		}
		if (input.eof()) {
			return root;;
		}
	}
	return root;
}

void calculateSizes(std::shared_ptr<day7> tree)
{
	for(auto var : tree->m_files) {
		tree->m_size += var.second;
	}
	for(auto node : tree->m_nodes) {
		calculateSizes(node);
		tree->m_size += node->m_size;
	}
}

long pt1(std::shared_ptr<day7> node)
{
	if (node->m_size <= 100'000) {
		totalSize += node->m_size;
	}
	for(auto node : node->m_nodes) {
		pt1(node);
	}
	return totalSize;
}

	}
}

