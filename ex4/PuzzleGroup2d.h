#pragma once
#ifndef PUZZLEGROUP2_D_H_INCLUDED
#define PUZZLEGROUP2_D_H_INCLUDED  
#include <vector>
#include "PuzzleGroupBase.h"
#include <iostream>


class PuzzleGroup2d : public PuzzleGroupBase
{
public:
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
			for (int j = 0; j < 4; j++)
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
			cout << j_indexes[0] << "  " << j_indexes[1] << "  " << j_indexes[2] << "  " << j_indexes[3] << endl;
			_mat[j_indexes[0]][j_indexes[1]][j_indexes[2]][j_indexes[3]].push_back(piece);
		}
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
