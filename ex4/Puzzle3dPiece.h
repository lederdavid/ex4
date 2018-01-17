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
	int edges[4]{};
	void to_string();
};


#endif

template <int T>
inline Puzzle3dPiece<T>::Puzzle3dPiece(const int a, const int b, const int c, const int d, const int e, const int f)
{
	assert(-1 * T <= a && a <= T);
	assert(-1 * T <= b && b <= T);
	assert(-1 * T <= c && c <= T);
	assert(-1 * T <= d && d <= T);
	assert(-1 * T <= e && e <= T);
	assert(-1 * T <= f && f <= T);
	edges[0] = a;
	edges[1] = b;
	edges[2] = c;
	edges[3] = d;
	edges[4] = e;
	edges[5] = f;
}

template <int T>
inline void Puzzle3dPiece<T>::to_string()
{
	cout << "{" << edges[0] << ", " << edges[1] << ", " << edges[2] << ", " << edges[3] << edges[4] << edges[5] << "}" <<
		endl;
}
