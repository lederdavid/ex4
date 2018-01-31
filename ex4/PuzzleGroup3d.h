#pragma once
#ifndef PUZZLEGROUP3_D_H_INCLUDED
#define PUZZLEGROUP3_D_H_INCLUDED  
#include <vector>
#include "PuzzlePieceBase.h"
#include <memory>
#include "PuzzleGroupBase.h"


class PuzzleGroup3d : public PuzzleGroupBase
{
public:
	void add(PuzzlePieceBase* piece) const
	{
		vector<int> edges = piece->get_edges();
		const int i0 = face_to_index(edges[0]);
		const int i1 = face_to_index(edges[1]);
		const int i2 = face_to_index(edges[2]);
		const int i3 = face_to_index(edges[3]);
		const int i4 = face_to_index(edges[4]);
		const int i5 = face_to_index(edges[5]);
		const int min = face_to_index(numeric_limits<int>::min());

		_mat[i0][i1][i2][i3][i4][i5].push_back(piece);

		_mat[i0][i1][i2][i3][i4][min].push_back(piece);

		_mat[i0][i1][i2][i3][min][i5].push_back(piece);
		_mat[i0][i1][i2][i3][min][min].push_back(piece);

		_mat[i0][i1][i2][min][i4][i5].push_back(piece);
		_mat[i0][i1][i2][min][i4][min].push_back(piece);
		_mat[i0][i1][i2][min][min][i5].push_back(piece);
		_mat[i0][i1][i2][min][min][min].push_back(piece);

		_mat[i0][i1][min][i3][i4][i5].push_back(piece);
		_mat[i0][i1][min][i3][i4][min].push_back(piece);
		_mat[i0][i1][min][i3][min][i5].push_back(piece);
		_mat[i0][i1][min][i3][min][min].push_back(piece);
		_mat[i0][i1][min][min][i4][i5].push_back(piece);
		_mat[i0][i1][min][min][i4][min].push_back(piece);
		_mat[i0][i1][min][min][min][i5].push_back(piece);
		_mat[i0][i1][min][min][min][min].push_back(piece);

		_mat[i0][min][i2][i3][i4][i5].push_back(piece);
		_mat[i0][min][i2][i3][i4][min].push_back(piece);
		_mat[i0][min][i2][i3][min][i5].push_back(piece);
		_mat[i0][min][i2][i3][min][min].push_back(piece);
		_mat[i0][min][i2][min][i4][i5].push_back(piece);
		_mat[i0][min][i2][min][i4][min].push_back(piece);
		_mat[i0][min][i2][min][min][i5].push_back(piece);
		_mat[i0][min][i2][min][min][min].push_back(piece);
		_mat[i0][min][min][i3][i4][i5].push_back(piece);
		_mat[i0][min][min][i3][i4][min].push_back(piece);
		_mat[i0][min][min][i3][min][i5].push_back(piece);
		_mat[i0][min][min][i3][min][min].push_back(piece);
		_mat[i0][min][min][min][i4][i5].push_back(piece);
		_mat[i0][min][min][min][i4][min].push_back(piece);
		_mat[i0][min][min][min][min][i5].push_back(piece);
		_mat[i0][min][min][min][min][min].push_back(piece);

		_mat[min][i1][i2][i3][i4][i5].push_back(piece);
		_mat[min][i1][i2][i3][i4][min].push_back(piece);
		_mat[min][i1][i2][i3][min][i5].push_back(piece);
		_mat[min][i1][i2][i3][min][min].push_back(piece);
		_mat[min][i1][i2][min][i4][i5].push_back(piece);
		_mat[min][i1][i2][min][i4][min].push_back(piece);
		_mat[min][i1][i2][min][min][i5].push_back(piece);
		_mat[min][i1][i2][min][min][min].push_back(piece);
		_mat[min][i1][min][i3][i4][i5].push_back(piece);
		_mat[min][i1][min][i3][i4][min].push_back(piece);
		_mat[min][i1][min][i3][min][i5].push_back(piece);
		_mat[min][i1][min][i3][min][min].push_back(piece);
		_mat[min][i1][min][min][i4][i5].push_back(piece);
		_mat[min][i1][min][min][i4][min].push_back(piece);
		_mat[min][i1][min][min][min][i5].push_back(piece);
		_mat[min][i1][min][min][min][min].push_back(piece);
		_mat[min][min][i2][i3][i4][i5].push_back(piece);
		_mat[min][min][i2][i3][i4][min].push_back(piece);
		_mat[min][min][i2][i3][min][i5].push_back(piece);
		_mat[min][min][i2][i3][min][min].push_back(piece);
		_mat[min][min][i2][min][i4][i5].push_back(piece);
		_mat[min][min][i2][min][i4][min].push_back(piece);
		_mat[min][min][i2][min][min][i5].push_back(piece);
		_mat[min][min][i2][min][min][min].push_back(piece);
		_mat[min][min][min][i3][i4][i5].push_back(piece);
		_mat[min][min][min][i3][i4][min].push_back(piece);
		_mat[min][min][min][i3][min][i5].push_back(piece);
		_mat[min][min][min][i3][min][min].push_back(piece);
		_mat[min][min][min][min][i4][i5].push_back(piece);
		_mat[min][min][min][min][i4][min].push_back(piece);
		_mat[min][min][min][min][min][i5].push_back(piece);
		_mat[min][min][min][min][min][min].push_back(piece);
	}

	PuzzleGroup3d(int k) :PuzzleGroupBase(k), _mat(nullptr)
	{
		init_mat();
	}

	virtual ~PuzzleGroup3d()
	{
		delete_mat();
	}


	PuzzleGroup3d(PuzzleGroup3d&& other) noexcept
		: PuzzleGroupBase(other._k),
		  _mat(nullptr)
	{
		init_mat();
		copy_mat(other._mat);
	}

	virtual vector<PuzzlePieceBase*> get(initializer_list<int> piece) const override
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
};

#endif
