#pragma once
#ifndef PUZZLE_GROUP_BASE_H_INCLUDED
#define PUZZLE_GROUP_BASE_H_INCLUDED
#include "PuzzleGroupData.h"


using namespace std;

class PuzzleGroupBase
{
public:
	PuzzleGroupBase(int k)
		: _k(k),
		  size(2*k + 2)
	{
	}

	virtual ~PuzzleGroupBase() = default;

	virtual vector<PuzzlePieceBase*> get(initializer_list<int> piece) const
	{
		return {};
	}
protected:
	
	int face_to_index(int k) const
	{
		if (k == numeric_limits<int>::min())
		{
			return size - 1;
		}
		return k + _k;
	}
	int _k;
	int size;
};

#endif