#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <vector>
#include <set>

using Position = std::pair<int, int>;

extern Position &realTail;
extern std::vector<Position> rope;
extern std::set<Position> positions ;

void moveHeadRight(Position &head, Position &tail);
void moveHeadLeft(Position &head, Position &tail);
void moveHeadDown(Position &head, Position &tail);
void moveHeadUp(Position &head, Position &tail);
void step(Position &head, Position &tail);

