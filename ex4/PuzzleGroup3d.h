#pragma once
#ifndef PUZZLEGROUP3_D_H_INCLUDED
#define PUZZLEGROUP3_D_H_INCLUDED  
#include <vector>
#include "Puzzle3dPiece.h"
#include <memory>


class PuzzleGroup3d
{
public:
	void init_mat()
	{
		_mat = new vector<PuzzlePieceBase*>*****[size];
		for (int a = 0; a < size; a++)
		{
			_mat[a] = new vector<PuzzlePieceBase*>****[size];
			for (int b = 0; b < size; b++)
			{
				_mat[a][b] = new vector<PuzzlePieceBase*>***[size];
				for (int c = 0; c < size; c++)
				{
					_mat[a][b][c] = new vector<PuzzlePieceBase*>**[size]();
					for (int d = 0; d < size; d++)
					{
						_mat[a][b][c][d] = new vector<PuzzlePieceBase*>*[size]();
						for (int e = 0; e < size; e++)
						{
							_mat[a][b][c][d][e] = new vector<PuzzlePieceBase*>[size]();
						}
					}
				}
			}
		}
	}

	void copy_mat(vector<PuzzlePieceBase*>****** other_mat) const
	{
		for (int a = 0; a < size; a++)
		{
			for (int b = 0; b < size; b++)
			{
				for (int c = 0; c < size; c++)
				{
					for (int d = 0; d < size; d++)
					{
						for (int e = 0; e < size; e++)
						{
							for (int f = 0; f < size; f++)
							{
								const vector<PuzzlePieceBase*> new_vec(other_mat[a][b][c][d][e][f]);
								_mat[a][b][c][d][e][f] = new_vec;
							}
						}
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
					for (int d = 0; d < size; d++)
					{
						for (int e = 0; e < size; e++)
						{
							delete[] _mat[a][b][c][d][e];
						}
						delete[] _mat[a][b][c][d];
					}
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

		int indexes[6] = {
			face_to_index(edges[0]), face_to_index(edges[1]), face_to_index(edges[2]), face_to_index(edges[3]),
			face_to_index(edges[4]), face_to_index(edges[5])
		};
		int j_indexes[6] = {};
		for (int i = 0; i < 64; i++)
		{
			int num = i;
			int i2 = 32;
			for (int j = 0; j < 6; j++)
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
			_mat[j_indexes[0]][j_indexes[1]][j_indexes[2]][j_indexes[3]][j_indexes[4]][j_indexes[5]].push_back(piece);
		}
	}

	PuzzleGroup3d(int k) : _mat(nullptr)
	{
		_k = k;
		size = 2 * _k + 2;
		init_mat();
	}

	~PuzzleGroup3d()
	{
		delete_mat();
	}


	PuzzleGroup3d(PuzzleGroup3d&& other) noexcept
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
		const int i4 = face_to_index(vec[4]);
		const int i5 = face_to_index(vec[5]);
		return _mat[i0][i1][i2][i3][i4][i5];
	}

private:
	int size;
	int _k;
	vector<PuzzlePieceBase*>****** _mat;

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
PuzzleGroup3d groupPuzzlePieces(iterator_type begin, iterator_type end)
{
	PuzzleGroup3d puzzle_group3d(begin->_K);
	for (iterator_type piece = begin; piece != end; ++piece)
	{
		puzzle_group3d.add(&(*piece));
	}
	return puzzle_group3d;
}


#endif
