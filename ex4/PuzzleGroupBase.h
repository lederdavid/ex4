#pragma once
#ifndef PUZZLE_GROUP_BASE_H_INCLUDED
#define PUZZLE_GROUP_BASE_H_INCLUDED
#include "PuzzleGroupData.h"


using namespace std;
/**
 * The class managing the puzzle groups to be given.
 */
class PuzzleGroupBase
{
public:
	PuzzleGroupBase(int k, int d);
	PuzzleGroupBase(PuzzleGroupBase&& other) noexcept;
	~PuzzleGroupBase();

	/**
	 * Gets the group of pieces that matches the given requirements
	 */
	vector<PuzzlePieceBase*> get(initializer_list<int> piece) const;

	/**
	 * Adds a piece to the puzzle groups
	 */
	void add(PuzzlePieceBase* piece) const;

	/**
	 * The range of each edge
	 */
	int _k;

	/**
	 * The size of allocated mat in each dimention
	 */
	int size;

private:
	PuzzleGroupData _data;
};

#endif