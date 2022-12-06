#include "day5.h"

int main(int argc, char *argv[])
{
	std::fstream input("../input", std::ios::in);
	std::string line;
	bool stackEnded = false;
	std::vector<std::vector<char>> preProcessed;
	std::vector<std::stack<char>> data;
	std::vector<step> procedure;

	while (std::getline(input, line)) {
		if (!stackEnded && line.find('[') == std::string::npos) {
			stackEnded = true;
			std::getline(input, line);
			continue;
		}
		if (!stackEnded) {
			preProcessed.push_back(readStack(line));
		} else {
			procedure.push_back(fillProcecureStep(line));
			// sprint(procedure.back());
		}
	}
	std::cout << "preprocessed" << std::endl;
	// for(auto var : preProcessed) {
	// 	vprint(var);
	// 	std::cout << std::endl;
	// }
	std::cout << std::endl;
	std::cout << "populating stack" << std::endl;
	data = std::move(populateStack(preProcessed));

	std::cout << "executing procedures" << std::endl;
	std::cout << "Initial tops" << std::endl;
	// printTops(data);
	// std::cout << std::endl;
	for(auto proc : procedure) {
		// printTops(data);
		std::stack<char> help;
		for (size_t i = 0; i < proc.move; i++) {
			help.push(data[proc.from-1].top());
			data[proc.from-1].pop();
		}
		for (size_t i = 0; i < proc.move; i++) {
			data[proc.to-1].push(help.top());
			help.pop();
		}
	}

	for(auto var : data) {
		std::cout << var.top();
	}
	std::cout << std::endl;

	return 0;
}

