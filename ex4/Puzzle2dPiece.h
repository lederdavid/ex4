#pragma once
#ifndef PUZZLE2_DPIECE_H_INCLUDED
#define PUZZLE2_DPIECE_H_INCLUDED   
#include <cassert>
#include "PuzzlePieceBase.h"
using namespace std;

template <int T>
class Puzzle2dPiece : public PuzzlePieceBase
{
public:
	Puzzle2dPiece(int a, int b, int c, int d);

	vector<int> get_edges() const override;
private:
	PuzzlePieceBase* base{};
	vector<int> _edges;
};


template <int T>
Puzzle2dPiece<T>::Puzzle2dPiece(const int a, const int b, const int c, const int d) : PuzzlePieceBase(T), _edges(4)
{
	_D = 2;
	assert(-1 * T <= a && a <= T);
	assert(-1 * T <= b && b <= T);
	assert(-1 * T <= c && c <= T);
	assert(-1 * T <= d && d <= T);
	_edges[0] = a;
	_edges[1] = b;
	_edges[2] = c;
	_edges[3] = d;
}


template <int T>
vector<int> Puzzle2dPiece<T>::get_edges() const
{
	return _edges;
}

#endif
