#pragma once
#ifndef PUZZLE2_DPIECE_H_INCLUDED
#define PUZZLE2_DPIECE_H_INCLUDED   
#include <vector>

template <int T>
class Puzzle2dPiece
{
public:
	Puzzle2dPiece(std::vector<int> edge);
	Puzzle2dPiece(int a, int b, int c, int d);
	int edges[4];
	void to_string();
};


#endif
