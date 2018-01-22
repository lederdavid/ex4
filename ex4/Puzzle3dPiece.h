#pragma once
#ifndef PUZZLE3_DPIECE_H_INCLUDED
#define PUZZLE3_DPIECE_H_INCLUDED   
#include <iostream>
#include <cassert>
using namespace std;

template <int T>
class Puzzle3dPiece
{
public:
	Puzzle3dPiece(int a, int b, int c, int d, int e, int f);
	int _edges[4]{};
	void to_string();
};


#endif

template <int T>
Puzzle3dPiece<T>::Puzzle3dPiece(const int a, const int b, const int c, const int d, const int e, const int f)
{
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
void Puzzle3dPiece<T>::to_string()
{
	cout << "{" << _edges[0] << ", " << _edges[1] << ", " << _edges[2] << ", " << _edges[3] << ", " << _edges[4] << ", " <<
		_edges[5] << "}" <<
		endl;
}
