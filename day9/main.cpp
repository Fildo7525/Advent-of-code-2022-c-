#include "day9.h"
#include <functional>
#include <string>
#include <vector>

// low 2822

int main(int argc, char *argv[])
{
	std::fstream input("../input", std::ios::in);
	std::string line;
	while (std::getline(input, line)) {
		char letter = line[0];
		int fields = std::stoi(line.substr(1));
		std::function<void(Position&, Position&)> move;
		std::function<void()> headMove;
		switch (letter) {
			case 'R':
				move = moveHeadRight;
				headMove = [&] { rope[0].second++; };
				break;
			case 'L':
				move = moveHeadLeft;
				headMove = [&] { rope[0].second--; };
				break;
			case 'U':
				move = moveHeadUp;
				headMove = [&] { rope[0].first--; };
				break;
			case 'D':
				move = moveHeadDown;
				headMove = [&] { rope[0].first++; };
				break;
		}
		for (size_t i = 0; i < fields; i++) {
			// std::cout << "TAIL: x: " << tail.first << " y: " << tail.second << std::endl;
			headMove();
			for (size_t j = 1; j < rope.size(); j++) {
				step(rope[j-1], rope[j]);
			}
			positions.insert(rope[9]);
		}
	}
	// std::vector<std::string> table;
	// for (size_t i = 0; i < 6; i++) {
	// 	table.push_back(std::string(6, '.'));
	// }
	//
	// for(auto var : positions) {
	// 	// std::cout << "x: " << var.first << " y: " << var.second << std::endl;
	// 	table[5+var.first][6-var.second] = '#';
	// }

	// std::copy(table.begin(), table.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	std::cout << "Number of visited fields: " << positions.size() << std::endl;
	return 0;
}

