#pragma once
#ifndef PUZZLEGROUP3_D_H_INCLUDED
#define PUZZLEGROUP3_D_H_INCLUDED  
#include <vector>
#include "Puzzle3dPiece.h"
#define ARRAY_FACTOR 50;

template <int T>
class PuzzleGroup3d
{
public:
	PuzzleGroup3d()
	= default;

	vector<Puzzle3dPiece<T>*> get(Puzzle3dPiece<T> piece)
	{
		vector<Puzzle3dPiece<T>*> result;
		// for each edge get the group that Snir calculated and add it to result vector
		const int index_a = piece._edges[0] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[0] + ARRAY_FACTOR;
		union_vectors_of_pieces(result, _a[index_a]);
		const int index_b = piece._edges[1] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[1] + ARRAY_FACTOR;
		union_vectors_of_pieces(result, _b[index_b]);
		const int index_c = piece._edges[2] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[2] + ARRAY_FACTOR;
		union_vectors_of_pieces(result, _c[index_c]);
		const int index_d = piece._edges[3] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[3] + ARRAY_FACTOR;
		union_vectors_of_pieces(result, _d[index_d]);
		const int index_e = piece._edges[4] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[4] + ARRAY_FACTOR;
		union_vectors_of_pieces(result, _e[index_e]);
		const int index_f = piece._edges[5] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[5] + ARRAY_FACTOR;
		union_vectors_of_pieces(result, _f[index_f]);

		return result;
	}

private:
	// -50 => 0, 0 => 50, 50 => 100, all => 101
	vector<Puzzle3dPiece<T>*> _a[101];
	vector<Puzzle3dPiece<T>*> _b[101];
	vector<Puzzle3dPiece<T>*> _c[101];
	vector<Puzzle3dPiece<T>*> _d[101];
	vector<Puzzle3dPiece<T>*> _e[101];
	vector<Puzzle3dPiece<T>*> _f[101];

	vector<Puzzle3dPiece<T>*> union_vectors_of_pieces(const vector<Puzzle3dPiece<T>*>& prev_result,
	                                                  const std::vector<Puzzle3dPiece<T>*>& puzzle_group_3_ds)
	{
		vector<Puzzle3dPiece<T>*> new_result;
		if (prev_result.empty()) // if result is empty add all the group
		{
			return puzzle_group_3_ds;
		}

		for (Puzzle3dPiece<T> piece : puzzle_group_3_ds) //find common pieces
		{
			if (std::find(prev_result.begin(), prev_result.end(), piece) != prev_result.end()) //piece is found in both vectors
			{
				new_result.push_back(piece);
			}
		}
		return new_result;
	}
};
#endif
