#pragma once
#ifndef PUZZLE2_DPIECE_H_INCLUDED
#define PUZZLE2_DPIECE_H_INCLUDED   
#include <iostream>
#include <cassert>
using namespace std;

template <int T>
class Puzzle2dPiece
{
public:
	Puzzle2dPiece(int a, int b, int c, int d);
	int _edges[4]{};
	void to_string();
	int _t;
};


template <int T>
Puzzle2dPiece<T>::Puzzle2dPiece(const int a, const int b, const int c, const int d) :_t(T)
{
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
void Puzzle2dPiece<T>::to_string()
{
	cout << "{" << _edges[0] << ", " << _edges[1] << ", " << _edges[2] << ", " << _edges[3] << "}" << endl;
}
#endif
