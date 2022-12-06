#include "day2.h"
#include <fstream>
#include <string>
#include <vector>

enum class rps {
	ROCK,
	PAPER,
	SCISORS,
};

rps deciferMySign(rps other, int outcome);
rps getHis(char c);
int getOutcome(char c);
int getPointsFromSign(rps sin);

int main(int argc, char *argv[])
{
	std::fstream input("../input", std::ios::in);
	std::string line;
	int totalScore = 0;
	while (std::getline(input, line)) {
		rps his = getHis(line[0]);
		rps me = deciferMySign(his, getOutcome(line[2]));
		// std::cout << "My sign " << int(me) << std::endl;
		totalScore += getPointsFromSign(me) + getOutcome(line[2]);
	}
	std::cout << "Score: " << totalScore << std::endl;
	return 0;
}

rps deciferMySign(rps other, int outcome)
{
	if (other == rps::ROCK) {
		if (outcome == 0) {
			return rps::SCISORS;
		} else if (outcome == 3) {
			return rps::ROCK;
		} else {
			return rps::PAPER;
		}
	} else if (other == rps::PAPER){
		if (outcome == 0) {
			return rps::ROCK;
		} else if (outcome == 3) {
			return rps::PAPER;
		} else {
			return rps::SCISORS;
		}
	} else {
		if (outcome == 0) {
			return rps::PAPER;
		} else if (outcome == 3) {
			return rps::SCISORS;
		} else {
			return rps::ROCK;
		}
	}
}

rps getHis(char c)
{
	switch (c) {
		case 'A':
			return rps::ROCK;
		case 'B':
			return rps::PAPER;
		case 'C':
			return rps::SCISORS;
	}
}

int getOutcome(char c)
{
	switch (c) {
		case 'X':
			return 0;
		case 'Y':
			return 3;
		case 'Z':
			return 6;
	}
}

int getPointsFromSign(rps sin)
{
	switch (sin) {
		case rps::ROCK:
			return 1;
		case rps::PAPER:
			return 2;
		case rps::SCISORS:
			return 3;
	}
}

