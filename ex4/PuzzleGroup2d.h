#pragma once
#ifndef PUZZLEGROUP2_D_H_INCLUDED
#define PUZZLEGROUP2_D_H_INCLUDED  
#include <vector>
#include "Puzzle2dPiece.h"
#include <memory>
#define ARRAY_FACTOR 50;


class PuzzleGroup2d
{
public:
	void init_mat()
	{
		_mat = new vector<shared_ptr<PuzzlePieceBase>>***[size];
		for (int a = 0; a < size; a++)
		{
			_mat[a] = new vector<shared_ptr<PuzzlePieceBase>>**[size];
			for (int b = 0; b < size; b++)
			{
				_mat[a][b] = new vector<shared_ptr<PuzzlePieceBase>>*[size];
				for (int c = 0; c < size; c++)
				{
					_mat[a][b][c] = new vector<shared_ptr<PuzzlePieceBase>>[size]();
				}
			}
		}
	}



	PuzzleGroup2d(const vector<shared_ptr<PuzzlePieceBase>>& pieces): _mat(nullptr)
	{
		assert(!pieces.empty());
		_k = pieces[0]->_K;

		size = 2 * _k + 2;
		_pieces = pieces;
		init_mat();

		for (const shared_ptr<PuzzlePieceBase>& piece : pieces)
		{
			vector<int> edges = piece->get_edges();
			const int i0 = face_to_index(edges[0]);
			const int i1 = face_to_index(edges[1]);
			const int i2 = face_to_index(edges[2]);
			const int i3 = face_to_index(edges[3]);
			const int min = face_to_index(numeric_limits<int>::min());

			_mat[i0][i1][i2][i3].push_back(piece);
			_mat[i0][i1][i2][min].push_back(piece);
			_mat[i0][i1][min][i3].push_back(piece);
			_mat[i0][i1][min][min].push_back(piece);
			_mat[i0][min][i2][i3].push_back(piece);
			_mat[i0][min][i2][min].push_back(piece);
			_mat[i0][min][min][i3].push_back(piece);
			_mat[i0][min][min][min].push_back(piece);
			_mat[min][i1][i2][i3].push_back(piece);
			_mat[min][i1][i2][min].push_back(piece);
			_mat[min][i1][min][i3].push_back(piece);
			_mat[min][i1][min][min].push_back(piece);
			_mat[min][min][i2][i3].push_back(piece);
			_mat[min][min][i2][min].push_back(piece);
			_mat[min][min][min][i3].push_back(piece);
			_mat[min][min][min][min].push_back(piece);
		}
	}

	vector<shared_ptr<PuzzlePieceBase>> get(PuzzlePieceBase piece)
	{
		vector<int> edges = piece.get_edges();

		int i0 = face_to_index(edges[0]);
		int i1 = face_to_index(edges[1]);
		int i2 = face_to_index(edges[2]);
		int i3 = face_to_index(edges[3]);
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
	int _k;

	vector<shared_ptr<PuzzlePieceBase>>**** _mat;

	vector<shared_ptr<PuzzlePieceBase>> _pieces;

	int face_to_index(int k) const
	{
		if (k == numeric_limits<int>::min())
		{
			return size - 1;
		}
		return k + _k;
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


template <class iterator_type>
PuzzleGroup2d groupPuzzlePieces(iterator_type begin, iterator_type end)
{
	int t = begin->_t;
	vector<PuzzlePieceBase> vector(begin, end);
	return PuzzlePieceBase(vector);
}


#endif
