#include "PuzzleGroupData.h"


using namespace std;


PuzzleGroupData::PuzzleGroupData(int k, int d)
	: _D(d),
	  size(2 * k + 2),
	  _k(k),
	  _3dmat(nullptr),
	  _2dmat(nullptr)
{
	init();
}

void PuzzleGroupData::init()
{
	if (_D == 2)
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
	}
	else
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

PuzzleGroupData::PuzzleGroupData(PuzzleGroupData& other)
	: _D(other._D),
	  size(other.size),
	  _k(other._k),
	  _3dmat(nullptr),
	  _2dmat(nullptr)
{
	init();
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

void PuzzleGroupData::free() const
{
	if (_D == 3)
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

vector<PuzzlePieceBase*> PuzzleGroupData::get(initializer_list<int> piece) const
{
	if (_D == 2)
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

void PuzzleGroupData::add(PuzzlePieceBase* piece) const
{
	vector<int> edges = piece->get_edges();
	const int min = face_to_index(numeric_limits<int>::min());
	if (_D == 3)
	{
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
			_3dmat[j_indexes[0]][j_indexes[1]][j_indexes[2]][j_indexes[3]][j_indexes[4]][j_indexes[5]].push_back(piece);
		}
	}
	else
	{
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
			_2dmat[j_indexes[0]][j_indexes[1]][j_indexes[2]][j_indexes[3]].push_back(piece);
		}
	}
}

int PuzzleGroupData::face_to_index(int k) const
{
	if (k == numeric_limits<int>::min())
	{
		return size - 1;
	}
	return k + _k;
}
