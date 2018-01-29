#pragma once
#ifndef PUZZLE_PIECE_BASE_H_INCLUDED
#define PUZZLE_PIECE_BASE_H_INCLUDED
#include <vector>

using namespace std;


class PuzzlePieceBase
{
public:
	virtual ~PuzzlePieceBase() = default;
	int _K;
	int _D;
	virtual vector<int> get_edges() const = 0;
	friend ostream& operator<<(ostream& lhs, const PuzzlePieceBase& rhs);
protected:
	PuzzlePieceBase(int K) :_K(K), _D(0)
	{
	};
};

inline ostream& operator<<(ostream& lhs, const PuzzlePieceBase& rhs)
{
	vector<int> edges = rhs.get_edges();
	if(rhs._D == 2)
	{
		lhs << "{" << edges[0] << ", " << edges[1] << ", " << edges[2] << ", " << edges[3] << "}";
	}
	else
	{
		lhs << "{" << edges[0] << ", " << edges[1] << ", " << edges[2] << ", " << edges[3] << ", " << edges[4] << ", " <<
			edges[5] << "}";
	}
	return lhs;
};
#endif
