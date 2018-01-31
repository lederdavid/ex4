#pragma once
#ifndef PUZZLE_GROUP_DATA_H_INCLUDED
#define PUZZLE_GROUP_DATA_H_INCLUDED
#include "PuzzlePieceBase.h"

using namespace std;

/**
 * The class holding the data needed for the puzzle groups
 */
class PuzzleGroupData
{
public:
	PuzzleGroupData(int k, int d);
	PuzzleGroupData(PuzzleGroupData& other);
	
	/**
	 * allocate memory for storage
	 */
	void init();

	/*
	 * Free the allocated data
	 */
	void free() const;

	/**
	* Gets the group of pieces that matches the given requirements
	*/
	vector<PuzzlePieceBase*> get(initializer_list<int> piece) const;

	/**
	* Adds a piece to the puzzle groups
	*/
	void add(PuzzlePieceBase* piece) const;

	/**
	 * The dimention of the puzzle pieces
	 */
	int _D;

	/**
	* The size of allocated mat in each dimention
	*/
	int size;
	
	/**
	* The range of each edge
	*/
	int _k;
private:
	vector<PuzzlePieceBase*>****** _3dmat;
	vector<PuzzlePieceBase*>**** _2dmat;
	/**
	* Normalize an edge requirement to fit the matrix size (negatives and numeric_limits.min)
	*/
	int face_to_index(int k) const;
};
#endif
