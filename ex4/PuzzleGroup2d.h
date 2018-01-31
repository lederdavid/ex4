#pragma once
#ifndef PUZZLEGROUP2_D_H_INCLUDED
#define PUZZLEGROUP2_D_H_INCLUDED  
#include <vector>
#include "PuzzlePieceBase.h"
#include <memory>
#include "PuzzleGroupBase.h"


class PuzzleGroup2d : public PuzzleGroupBase
{
public:
	void add(PuzzlePieceBase* piece) const
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

	PuzzleGroup2d(int k): PuzzleGroupBase(k), _mat(nullptr)
	{
		init_mat();
	}

	virtual ~PuzzleGroup2d()
	{
		delete_mat();
	}


	PuzzleGroup2d(PuzzleGroup2d&& other) noexcept
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
		return _mat[i0][i1][i2][i3];
	}

private:
	vector<PuzzlePieceBase*>**** _mat;
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
};





#endif
