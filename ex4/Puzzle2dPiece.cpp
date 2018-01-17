#include "Puzzle2dPiece.h"
#include <iostream>
#include <cassert>
using namespace std;

template<int T>
Puzzle2dPiece<T>::Puzzle2dPiece()
{
}

template <int T>
Puzzle2dPiece<T>::Puzzle2dPiece(std::vector<int> edges)
{
	assert(edges.size() == 4);
	for (int i = 0; i < 4; i++)
	{
		assert(-1 * T <= edges[i] && edges[i] <= T);

		this->edges[i] = edges[i];
	}
}

template <int T>
Puzzle2dPiece<T>::Puzzle2dPiece(const int a, const int b, const int c, const int d)
{
	assert(-1 * T <= a && a <= T);
	assert(-1 * T <= b && b <= T);
	assert(-1 * T <= c && a <= T);
	assert(-1 * T <= a && c <= T);
	edges[0] = a;
	edges[1] = b;
	edges[2] = c;
	edges[3] = d;
}

template <int T>
void Puzzle2dPiece<T>::to_string()
{
	cout << "{" << edges[0] << ", " << edges[1] << ", " << edges[2] << ", " << edges[3] << "}" << endl;;
}
