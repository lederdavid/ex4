#pragma once
#ifndef PUZZLE_PIECE_BASE_H_INCLUDED
#define PUZZLE_PIECE_BASE_H_INCLUDED
#include <vector>
#include <iostream>

using namespace std;

/**
 * Virtual base class that holds the parameter (T), the dimensions of the piece, and an array of its edges
 */
class PuzzlePieceBase
{
public:
	virtual ~PuzzlePieceBase()
	= default;
	int _K; //parameter T of puzzle piece
	int _D; //dimensions
	virtual vector<int> get_edges() const = 0;
	/**
	 * override operator << to work as to_string()
	 */
	friend ostream& operator<<(ostream& lhs, const PuzzlePieceBase& rhs);
protected:
	PuzzlePieceBase(int K) : _K(K), _D(0)
	{
	};
};

#endif
