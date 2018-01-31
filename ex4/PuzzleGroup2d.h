#pragma once
#ifndef PUZZLEGROUP2_D_H_INCLUDED
#define PUZZLEGROUP2_D_H_INCLUDED  
#include <vector>
#include "Puzzle2dPiece.h"
#include <memory>


class PuzzleGroup2d
{
public:
	void init_mat()
	{
		_mat = new vector<PuzzlePieceBase*>***[size];
		for (int a = 0; a < size; a++)
		{
			_mat[a] = new vector<PuzzlePieceBase*>**[size];
			for (int b = 0; b < size; b++)
			{
				_mat[a][b] = new vector<PuzzlePieceBase*>*[size];
				for (int c = 0; c < size; c++)
				{
					_mat[a][b][c] = new vector<PuzzlePieceBase*>[size]();
				}
			}
		}
	}

	void copy_mat(vector<PuzzlePieceBase*>**** other_mat) const
	{
		for (int a = 0; a < size; a++)
		{
			for (int b = 0; b < size; b++)
			{
				for (int c = 0; c < size; c++)
				{
					for (int d = 0; d < size; d++)
					{
						const vector<PuzzlePieceBase*> new_vec(other_mat[a][b][c][d]);
						_mat[a][b][c][d] = new_vec;
					}
				}
			}
		}
	}

	void delete_mat() const
	{
		for (int a = 0; a < size; a++)
		{
			for (int b = 0; b < size; b++)
			{
				for (int c = 0; c < size; c++)
				{
					delete[] _mat[a][b][c];
				}
				delete[] _mat[a][b];
			}
			delete[] _mat[a];
		}
		delete[] _mat;
	}

	void add(PuzzlePieceBase* piece) const
	{
		vector<int> edges = piece->get_edges();
		const int min = face_to_index(numeric_limits<int>::min());

		int indexes[4] = {face_to_index(edges[0]), face_to_index(edges[1]), face_to_index(edges[2]), face_to_index(edges[3])};
		int j_indexes[4] = {};
		for (int i = 0; i < 16; i++)
		{
			int num = i;
			int i2 = 8;
			for (int j = 0; j < 3; j++)
			{
				if (num / i2 == 0)
				{
					j_indexes[j] = indexes[j];
				}
				else
				{
					j_indexes[j] = min;
					num -= i2;
				}
				i2 /= 2;
			}
			_mat[j_indexes[0]][j_indexes[1]][j_indexes[2]][j_indexes[3]].push_back(piece);
		}
	}

	PuzzleGroup2d(int k): _mat(nullptr)
	{
		_k = k;
		size = 2 * _k + 2;
		init_mat();
	}

	~PuzzleGroup2d()
	{
		delete_mat();
	}


	PuzzleGroup2d(PuzzleGroup2d&& other) noexcept
		: size(other.size),
		  _k(other._k),
		  _mat(nullptr)
	{
		init_mat();
		copy_mat(other._mat);
	}

	vector<PuzzlePieceBase*> get(initializer_list<int> piece) const
	{
		vector<int> vec(piece);

		const int i0 = face_to_index(vec[0]);
		const int i1 = face_to_index(vec[1]);
		const int i2 = face_to_index(vec[2]);
		const int i3 = face_to_index(vec[3]);
		return _mat[i0][i1][i2][i3];
	}

private:
	int size;
	int _k;
	vector<PuzzlePieceBase*>**** _mat;

	int face_to_index(int k) const
	{
		if (k == numeric_limits<int>::min())
		{
			return size - 1;
		}
		return k + _k;
	}
};


template <class iterator_type>
PuzzleGroup2d groupPuzzlePieces(iterator_type begin, iterator_type end)
{
	PuzzleGroup2d puzzle_group2d(begin->_K);
	for (iterator_type piece = begin; piece != end; ++piece)
	{
		puzzle_group2d.add(&(*piece));
	}
	return puzzle_group2d;
}


#endif
