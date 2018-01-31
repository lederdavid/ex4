#pragma once
#ifndef PUZZLE_GROUP_BASE_H_INCLUDED
#define PUZZLE_GROUP_BASE_H_INCLUDED
#include "PuzzleGroupData.h"


using namespace std;

class PuzzleGroupBase
{
public:
	PuzzleGroupBase(int k, int d)
		: _k(k),
		  size(2*k + 2),
		 _data(k, d)
	{
	}

	PuzzleGroupBase(PuzzleGroupBase&& other) noexcept
		: _k(other._k),
		  size(other.size),
		  _data(other._data)
	{
	}

	~PuzzleGroupBase()
	{
		_data.free();
	}

	vector<PuzzlePieceBase*> get(initializer_list<int> piece) const
	{
		return _data.get(piece);
	}
	void add(PuzzlePieceBase* piece) const
	{
		_data.add(piece);
	}

	int _k;
	int size;
private:
	PuzzleGroupData _data;
};

#endif