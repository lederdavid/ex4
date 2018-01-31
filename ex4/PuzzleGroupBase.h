#pragma once
#ifndef PUZZLE_GROUP_BASE_H_INCLUDED
#define PUZZLE_GROUP_BASE_H_INCLUDED
#include "PuzzleGroupData.h"


using namespace std;

class PuzzleGroupBase
{
public:
	PuzzleGroupBase(int k, int d);
	PuzzleGroupBase(PuzzleGroupBase&& other) noexcept;
	~PuzzleGroupBase();

	vector<PuzzlePieceBase*> get(initializer_list<int> piece) const;
	void add(PuzzlePieceBase* piece) const;

	int _k;
	int size;
private:
	PuzzleGroupData _data;
};

#endif