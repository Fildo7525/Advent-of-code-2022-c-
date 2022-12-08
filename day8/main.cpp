#include "day8.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

long visible = 0;
std::vector<std::string> field;
std::vector<long> vis(4);

bool checkLeft(char peak, int x, int y);
bool checkRight(char peak, int x, int y);
bool checkUp(char peak, int x, int y);
bool checkDown(char peak, int x, int y);

int main(int argc, char *argv[])
{
	std::fstream input("../input", std::ios::in);
	std::string line;
	long highestScore = 0;

	while (std::getline(input, line)) {
		field.push_back(std::move(line));
	}
	for (size_t i = 0; i < field.size(); i++) {
		for (size_t j = 0; j < field[i].size(); j++) {
			checkLeft(field[i][j], i, j-1);
			checkRight(field[i][j], i, j+1);
			checkUp(field[i][j], i-1, j);
			checkDown(field[i][j], i+1, j);
			auto tmp = vis[0] * vis[1] * vis[2] * vis[3];
			highestScore = (highestScore < tmp ? tmp : highestScore);
			vis[0] = vis[1] = vis[2] = vis[3] = 0;
		}
	}
	std::cout << "Visible trees: " << highestScore << '\n' << std::endl;
	// std::copy(visibility.cbegin(), visibility.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
	return 0;
}

bool checkLeft(char peak, int x, int y)
{
	vis[0]++;
	if (x < 0 || y < 0 || x >= field.size() || y >= field[x].size()) {
		vis[0]--;
		return true;
	} else if (field[x][y] < peak) {
		return checkLeft(peak, x, y-1);
	}
	return false;
}

bool checkRight(char peak, int x, int y)
{
	vis[1]++;
	if (x <= 0 || y <= 0 || x >= field.size() || y >= field[x].size()) {
		vis[1]--;
		return true;
	} else if (field[x][y] < peak) {
		return checkRight(peak, x, y+1);
	}
	return false;
}

bool checkUp(char peak, int x, int y)
{
	vis[2]++;
	if (x < 0 || y < 0 || x >= field.size() || y >= field[x].size()) {
		vis[2]--;
		return true;
	} else if (field[x][y] < peak) {
		return checkUp(peak, x-1, y);
	}
	return false;
}

bool checkDown(char peak, int x, int y)
{
	vis[3]++;
	if (x < 0 || y < 0 || x >= field.size() || y >= field[x].size()) {
		vis[3]--;
		return true;
	} else if (field[x][y] < peak) {
		return checkDown(peak, x+1, y);
	}
	return false;
}

