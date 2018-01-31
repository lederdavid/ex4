#pragma once
#ifndef PUZZLE3_DPIECE_H_INCLUDED
#define PUZZLE3_DPIECE_H_INCLUDED   
#include <iostream>
#include <cassert>
#include "PuzzlePieceBase.h"
using namespace std;

template <int T>
class Puzzle3dPiece : public PuzzlePieceBase
{
public:
	Puzzle3dPiece(int a, int b, int c, int d, int e, int f);
	vector<int> get_edges() const override;
private:
	PuzzlePieceBase* base{};
	vector<int> _edges;
};


template <int T>
Puzzle3dPiece<T>::
Puzzle3dPiece(const int a, const int b, const int c, const int d, const int e, const int f) : PuzzlePieceBase(T), _edges(6)
{
	_D = 3;
	assert(-1 * T <= a && a <= T);
	assert(-1 * T <= b && b <= T);
	assert(-1 * T <= c && c <= T);
	assert(-1 * T <= d && d <= T);
	assert(-1 * T <= e && e <= T);
	assert(-1 * T <= f && f <= T);
	_edges[0] = a;
	_edges[1] = b;
	_edges[2] = c;
	_edges[3] = d;
	_edges[4] = e;
	_edges[5] = f;
}

template <int T>
vector<int> Puzzle3dPiece<T>::get_edges() const
{
	return _edges;
}


#endif
