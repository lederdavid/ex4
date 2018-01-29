#pragma once
#ifndef PUZZLE_PIECE_BASE_H_INCLUDED
#define PUZZLE_PIECE_BASE_H_INCLUDED
#include <vector>

using namespace std;


class PuzzlePieceBase
{
public:
	PuzzlePieceBase(int K)
	{
		_K = K;
	};
	virtual ~PuzzlePieceBase() = default;
	int _K;
	virtual vector<int> get_edges() = 0;
	virtual void to_string() = 0;
};


#endif
