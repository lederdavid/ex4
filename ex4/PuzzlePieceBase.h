#pragma once
#ifndef PUZZLE_PIECE_BASE_H_INCLUDED
#define PUZZLE_PIECE_BASE_H_INCLUDED
#include <vector>
#include <iostream>
using namespace std;


class PuzzlePieceBase
{
public:
	virtual ~PuzzlePieceBase();
	int _K;
	int _D;
	virtual vector<int> get_edges() const = 0;
	friend ostream& operator<<(ostream& lhs, const PuzzlePieceBase& rhs);
protected:
	PuzzlePieceBase(int K) : _K(K), _D(0)
	{
	};
};

#endif
