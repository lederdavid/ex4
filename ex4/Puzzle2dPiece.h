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
	int edges[4]{};
	void to_string();
};




template <int T>
inline Puzzle2dPiece<T>::Puzzle2dPiece(const int a, const int b, const int c, const int d)
{
	assert(-1 * T <= a && a <= T);
	assert(-1 * T <= b && b <= T);
	assert(-1 * T <= c && c <= T);
	assert(-1 * T <= d && d <= T);
	edges[0] = a;
	edges[1] = b;
	edges[2] = c;
	edges[3] = d;
}

template <int T>
inline void Puzzle2dPiece<T>::to_string()
{
	cout << "{" << edges[0] << ", " << edges[1] << ", " << edges[2] << ", " << edges[3] << "}" << endl;
}
#endif