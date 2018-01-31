#pragma once
#ifndef PUZZLE_GROUP_DATA_H_INCLUDED
#define PUZZLE_GROUP_DATA_H_INCLUDED
#include "PuzzlePieceBase.h"


using namespace std;

class PuzzleGroupData
{
public:
	PuzzleGroupData(int k, int d)
		: _D(d),
		  size(2*k +2),
		  _k(k),
		  _3dmat(nullptr),
		  _2dmat(nullptr)
	{
	}

	void init()
	{
		if(_D == 2)
		{
			_2dmat = new vector<PuzzlePieceBase*>***[size];
			for (int a = 0; a < size; a++)
			{
				_2dmat[a] = new vector<PuzzlePieceBase*>**[size];
				for (int b = 0; b < size; b++)
				{
					_2dmat[a][b] = new vector<PuzzlePieceBase*>*[size];
					for (int c = 0; c < size; c++)
					{
						_2dmat[a][b][c] = new vector<PuzzlePieceBase*>[size]();
					}
				}
			}
		}else
		{
			_3dmat = new vector<PuzzlePieceBase*>*****[size];
			for (int a = 0; a < size; a++)
			{
				_3dmat[a] = new vector<PuzzlePieceBase*>****[size];
				for (int b = 0; b < size; b++)
				{
					_3dmat[a][b] = new vector<PuzzlePieceBase*>***[size];
					for (int c = 0; c < size; c++)
					{
						_3dmat[a][b][c] = new vector<PuzzlePieceBase*>**[size]();
						for (int d = 0; d < size; d++)
						{
							_3dmat[a][b][c][d] = new vector<PuzzlePieceBase*>*[size]();
							for (int e = 0; e < size; e++)
							{
								_3dmat[a][b][c][d][e] = new vector<PuzzlePieceBase*>[size]();
							}
						}
					}
				}
			}
		}
	}

	PuzzleGroupData(PuzzleGroupData& other)
		: _D(other._D),
		size(other.size),
		_k(other._k),
		_3dmat(nullptr),
		_2dmat(nullptr)
	{
		if (_D == 2)
		{
			for (int a = 0; a < size; a++)
			{
				for (int b = 0; b < size; b++)
				{
					for (int c = 0; c < size; c++)
					{
						for (int d = 0; d < size; d++)
						{
							const vector<PuzzlePieceBase*> new_vec(other._2dmat[a][b][c][d]);
							_2dmat[a][b][c][d] = new_vec;
						}
					}
				}
			}
		}
		else
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
									const vector<PuzzlePieceBase*> new_vec(other._3dmat[a][b][c][d][e][f]);
									_3dmat[a][b][c][d][e][f] = new_vec;
								}
							}
						}
					}
				}
			}
		}
	}

	void free()
	{
		if(_D ==3)
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
								delete[] _3dmat[a][b][c][d][e];
							}
							delete[] _3dmat[a][b][c][d];
						}
						delete[] _3dmat[a][b][c];
					}
					delete[] _3dmat[a][b];
				}
				delete[] _3dmat[a];
			}
			delete[] _3dmat;
		}
		else
		{
			for (int a = 0; a < size; a++)
			{
				for (int b = 0; b < size; b++)
				{
					for (int c = 0; c < size; c++)
					{
						delete[] _2dmat[a][b][c];
					}
					delete[] _2dmat[a][b];
				}
				delete[] _2dmat[a];
			}
			delete[] _2dmat;
		}
		
	}

	vector<PuzzlePieceBase*> get(initializer_list<int> piece) const
	{
		if (_D==2)
		{
			vector<int> vec(piece);

			const int i0 = face_to_index(vec[0]);
			const int i1 = face_to_index(vec[1]);
			const int i2 = face_to_index(vec[2]);
			const int i3 = face_to_index(vec[3]);
			return _2dmat[i0][i1][i2][i3];
		}
		else
		{
			vector<int> vec(piece);

			const int i0 = face_to_index(vec[0]);
			const int i1 = face_to_index(vec[1]);
			const int i2 = face_to_index(vec[2]);
			const int i3 = face_to_index(vec[3]);
			const int i4 = face_to_index(vec[4]);
			const int i5 = face_to_index(vec[5]);
			return _3dmat[i0][i1][i2][i3][i4][i5];
		}
	}

	void add(PuzzlePieceBase* piece) const
	{
		if(_D == 3)
		{
			vector<int> edges = piece->get_edges();
			const int i0 = face_to_index(edges[0]);
			const int i1 = face_to_index(edges[1]);
			const int i2 = face_to_index(edges[2]);
			const int i3 = face_to_index(edges[3]);
			const int i4 = face_to_index(edges[4]);
			const int i5 = face_to_index(edges[5]);
			const int min = face_to_index(numeric_limits<int>::min());

			_3dmat[i0][i1][i2][i3][i4][i5].push_back(piece);

			_3dmat[i0][i1][i2][i3][i4][min].push_back(piece);

			_3dmat[i0][i1][i2][i3][min][i5].push_back(piece);
			_3dmat[i0][i1][i2][i3][min][min].push_back(piece);

			_3dmat[i0][i1][i2][min][i4][i5].push_back(piece);
			_3dmat[i0][i1][i2][min][i4][min].push_back(piece);
			_3dmat[i0][i1][i2][min][min][i5].push_back(piece);
			_3dmat[i0][i1][i2][min][min][min].push_back(piece);

			_3dmat[i0][i1][min][i3][i4][i5].push_back(piece);
			_3dmat[i0][i1][min][i3][i4][min].push_back(piece);
			_3dmat[i0][i1][min][i3][min][i5].push_back(piece);
			_3dmat[i0][i1][min][i3][min][min].push_back(piece);
			_3dmat[i0][i1][min][min][i4][i5].push_back(piece);
			_3dmat[i0][i1][min][min][i4][min].push_back(piece);
			_3dmat[i0][i1][min][min][min][i5].push_back(piece);
			_3dmat[i0][i1][min][min][min][min].push_back(piece);

			_3dmat[i0][min][i2][i3][i4][i5].push_back(piece);
			_3dmat[i0][min][i2][i3][i4][min].push_back(piece);
			_3dmat[i0][min][i2][i3][min][i5].push_back(piece);
			_3dmat[i0][min][i2][i3][min][min].push_back(piece);
			_3dmat[i0][min][i2][min][i4][i5].push_back(piece);
			_3dmat[i0][min][i2][min][i4][min].push_back(piece);
			_3dmat[i0][min][i2][min][min][i5].push_back(piece);
			_3dmat[i0][min][i2][min][min][min].push_back(piece);
			_3dmat[i0][min][min][i3][i4][i5].push_back(piece);
			_3dmat[i0][min][min][i3][i4][min].push_back(piece);
			_3dmat[i0][min][min][i3][min][i5].push_back(piece);
			_3dmat[i0][min][min][i3][min][min].push_back(piece);
			_3dmat[i0][min][min][min][i4][i5].push_back(piece);
			_3dmat[i0][min][min][min][i4][min].push_back(piece);
			_3dmat[i0][min][min][min][min][i5].push_back(piece);
			_3dmat[i0][min][min][min][min][min].push_back(piece);

			_3dmat[min][i1][i2][i3][i4][i5].push_back(piece);
			_3dmat[min][i1][i2][i3][i4][min].push_back(piece);
			_3dmat[min][i1][i2][i3][min][i5].push_back(piece);
			_3dmat[min][i1][i2][i3][min][min].push_back(piece);
			_3dmat[min][i1][i2][min][i4][i5].push_back(piece);
			_3dmat[min][i1][i2][min][i4][min].push_back(piece);
			_3dmat[min][i1][i2][min][min][i5].push_back(piece);
			_3dmat[min][i1][i2][min][min][min].push_back(piece);
			_3dmat[min][i1][min][i3][i4][i5].push_back(piece);
			_3dmat[min][i1][min][i3][i4][min].push_back(piece);
			_3dmat[min][i1][min][i3][min][i5].push_back(piece);
			_3dmat[min][i1][min][i3][min][min].push_back(piece);
			_3dmat[min][i1][min][min][i4][i5].push_back(piece);
			_3dmat[min][i1][min][min][i4][min].push_back(piece);
			_3dmat[min][i1][min][min][min][i5].push_back(piece);
			_3dmat[min][i1][min][min][min][min].push_back(piece);
			_3dmat[min][min][i2][i3][i4][i5].push_back(piece);
			_3dmat[min][min][i2][i3][i4][min].push_back(piece);
			_3dmat[min][min][i2][i3][min][i5].push_back(piece);
			_3dmat[min][min][i2][i3][min][min].push_back(piece);
			_3dmat[min][min][i2][min][i4][i5].push_back(piece);
			_3dmat[min][min][i2][min][i4][min].push_back(piece);
			_3dmat[min][min][i2][min][min][i5].push_back(piece);
			_3dmat[min][min][i2][min][min][min].push_back(piece);
			_3dmat[min][min][min][i3][i4][i5].push_back(piece);
			_3dmat[min][min][min][i3][i4][min].push_back(piece);
			_3dmat[min][min][min][i3][min][i5].push_back(piece);
			_3dmat[min][min][min][i3][min][min].push_back(piece);
			_3dmat[min][min][min][min][i4][i5].push_back(piece);
			_3dmat[min][min][min][min][i4][min].push_back(piece);
			_3dmat[min][min][min][min][min][i5].push_back(piece);
			_3dmat[min][min][min][min][min][min].push_back(piece);
		}else
		{
			vector<int> edges = piece->get_edges();
			const int i0 = face_to_index(edges[0]);
			const int i1 = face_to_index(edges[1]);
			const int i2 = face_to_index(edges[2]);
			const int i3 = face_to_index(edges[3]);
			const int min = face_to_index(numeric_limits<int>::min());

			_2dmat[i0][i1][i2][i3].push_back(piece);
			_2dmat[i0][i1][i2][min].push_back(piece);
			_2dmat[i0][i1][min][i3].push_back(piece);
			_2dmat[i0][i1][min][min].push_back(piece);
			_2dmat[i0][min][i2][i3].push_back(piece);
			_2dmat[i0][min][i2][min].push_back(piece);
			_2dmat[i0][min][min][i3].push_back(piece);
			_2dmat[i0][min][min][min].push_back(piece);
			_2dmat[min][i1][i2][i3].push_back(piece);
			_2dmat[min][i1][i2][min].push_back(piece);
			_2dmat[min][i1][min][i3].push_back(piece);
			_2dmat[min][i1][min][min].push_back(piece);
			_2dmat[min][min][i2][i3].push_back(piece);
			_2dmat[min][min][i2][min].push_back(piece);
			_2dmat[min][min][min][i3].push_back(piece);
			_2dmat[min][min][min][min].push_back(piece);
		}
	}
	int _D;
	int size;
	int _k;
private:
	vector<PuzzlePieceBase*>****** _3dmat;
	vector<PuzzlePieceBase*>**** _2dmat;


	int face_to_index(int k) const
	{
		if (k == numeric_limits<int>::min())
		{
			return size - 1;
		}
		return k + _k;
	}
};
#endif
