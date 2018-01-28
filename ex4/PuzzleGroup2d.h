#pragma once
#ifndef PUZZLEGROUP2_D_H_INCLUDED
#define PUZZLEGROUP2_D_H_INCLUDED  
#include <vector>
#include "Puzzle2dPiece.h"
#define ARRAY_FACTOR 50;


template <int T>
class PuzzleGroup2d
{
	
public:
	PuzzleGroup2d(vector<Puzzle2dPiece<T>> pieces)
	{
		size = 2 * T +2;
		_pieces = pieces;
		for (Puzzle2dPiece<T> elem : _pieces)
		{
			int i0 = face_to_index(elem->_edges[0]);
			int i1 = face_to_index(elem->_edges[1]);
			int i2 = face_to_index(elem->_edges[2]);
			int i3 = face_to_index(elem->_edges[3]);
			int min = face_to_index(numeric_limits<int>::min());

			_mat[i0][i1][i2][i3].push_back(&elem);
			_mat[i0][i1][i2][min].push_back(&elem);
			_mat[i0][i1][min][i3].push_back(&elem);
			_mat[i0][i1][min][min].push_back(&elem);
			_mat[i0][min][i2][i3].push_back(&elem);
			_mat[i0][min][i2][min].push_back(&elem);
			_mat[i0][min][min][i3].push_back(&elem);
			_mat[i0][min][min][min].push_back(&elem);
			_mat[min][i1][i2][i3].push_back(&elem);
			_mat[min][i1][i2][min].push_back(&elem);
			_mat[min][i1][min][i3].push_back(&elem);
			_mat[min][i1][min][min].push_back(&elem);
			_mat[min][min][i2][i3].push_back(&elem);
			_mat[min][min][i2][min].push_back(&elem);
			_mat[min][min][min][i3].push_back(&elem);
			_mat[min][min][min][min].push_back(&elem);
		}
	}

	vector<Puzzle2dPiece<T>*> get(Puzzle2dPiece<T> piece)
	{
		int i0 = face_to_index(piece->_edges[0]);
		int i1 = face_to_index(piece->_edges[1]);
		int i2 = face_to_index(piece->_edges[2]);
		int i3 = face_to_index(piece->_edges[3]);
		return _mat[i0][i1][i2][i3];
	}

	// vector<Puzzle2dPiece<T>*> get(Puzzle2dPiece<T> piece)
	// {
	// 	vector<Puzzle2dPiece<T>*> result;
	// 	// for each edge get the group that Snir calculated and add it to result vector
	// 	const int index_a = piece._edges[0] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[0] + ARRAY_FACTOR;
	// 	union_vectors_of_pieces(result, _a[index_a]);
	// 	const int index_b = piece._edges[1] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[1] + ARRAY_FACTOR;
	// 	union_vectors_of_pieces(result, _b[index_b]);
	// 	const int index_c = piece._edges[2] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[2] + ARRAY_FACTOR;
	// 	union_vectors_of_pieces(result, _c[index_c]);
	// 	const int index_d = piece._edges[3] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[3] + ARRAY_FACTOR;
	// 	union_vectors_of_pieces(result, _d[index_d]);
	// 
	// 	return result;
	// }

private:
	int size;
	vector<Puzzle2dPiece<T>*> _mat[T][T][T][T];

	vector<Puzzle2dPiece<T>> _pieces;

	int face_to_index(int k)
	{
		if (k == numeric_limits<int>::min())
		{
			return size - 1;
		}
		return k + T;
	}
	// -50 => 0, 0 => 50, 50 => 100, all => 101
	// vector<Puzzle2dPiece<T>*> _a[101];
	// vector<Puzzle2dPiece<T>*> _b[101];
	// vector<Puzzle2dPiece<T>*> _c[101];
	// vector<Puzzle2dPiece<T>*> _d[101];
	// 
	// 
	// vector<Puzzle2dPiece<T>*> union_vectors_of_pieces(const vector<Puzzle2dPiece<T>*>& prev_result,
	//                                                   const std::vector<Puzzle2dPiece<T>*>& puzzle_group_2_ds)
	// {
	// 	vector<Puzzle2dPiece<T>*> new_result;
	// 	if (prev_result.empty()) // if result is empty add all the group
	// 	{
	// 		return puzzle_group_2_ds;
	// 	}
	// 
	// 	for (Puzzle2dPiece<T> piece : puzzle_group_2_ds) //find common pieces
	// 	{
	// 		if (std::find(prev_result.begin(), prev_result.end(), piece) != prev_result.end()) //piece is found in both vectors
	// 		{
	// 			new_result.push_back(piece);
	// 		}
	// 	}
	// 	return new_result;
	// }
};


template<class iterator_type, int T>
PuzzleGroup2d<T> groupPuzzlePieces(iterator_type begin, iterator_type end)
{
	int t = begin->_t;
	vector<Puzzle2dPiece<T>> vector(begin, end);
	return PuzzleGroup2d<T>(vector);
}


#endif
