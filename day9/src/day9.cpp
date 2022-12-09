#include "day9.h"
#include <vector>

std::vector<Position> rope(10);
Position& realTail = rope[9];
std::set<Position> positions;

void moveHeadRight(Position &head, Position &tail)
{
	if (std::abs(head.first - tail.first) > 1
	|| std::abs(head.second - tail.second) > 1) {
		tail = head;
		tail.second--;
	}
	positions.insert(realTail);
}

void moveHeadLeft(Position &head, Position &tail)
{
	if (std::abs(head.first - tail.first) > 1
	|| std::abs(head.second - tail.second) > 1) {
		tail = head;
		tail.second++;
	}
	positions.insert(realTail);
}

void moveHeadDown(Position &head, Position &tail)
{
	if (std::abs(head.first - tail.first) > 1
	|| std::abs(head.second - tail.second) > 1) {
		tail = head;
		tail.first--;
	}
	positions.insert(realTail);
}

void moveHeadUp(Position &head, Position &tail)
{
	if (std::abs(head.first - tail.first) > 1
	|| std::abs(head.second - tail.second) > 1) {
		tail = head;
		tail.first++;
	}
	positions.insert(realTail);
}

void step(Position &head, Position &tail)
{
	if (std::abs(head.first - tail.first) > 1) {
		tail.first += (head.first - tail.first) / 2;
		if (std::abs(head.second - tail.second) > 1)
			tail.second += (head.second - tail.second) / 2;
		else
			tail.second += head.second - tail.second;
	} else if (std::abs(head.second - tail.second) > 1) {
		tail.second += (head.second - tail.second) / 2;
		tail.first += head.first - tail.first;
	}
}

