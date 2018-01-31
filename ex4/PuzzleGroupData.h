#pragma once
#ifndef PUZZLE_GROUP_DATA_H_INCLUDED
#define PUZZLE_GROUP_DATA_H_INCLUDED
#include "PuzzlePieceBase.h"


using namespace std;

class PuzzleGroupData
{
public:
	PuzzleGroupData(int k, int d);
	PuzzleGroupData(PuzzleGroupData& other);
	void init();
	void free() const;
	vector<PuzzlePieceBase*> get(initializer_list<int> piece) const;
	void add(PuzzlePieceBase* piece) const;
	int _D;
	int size;
	int _k;
private:
	vector<PuzzlePieceBase*>****** _3dmat;
	vector<PuzzlePieceBase*>**** _2dmat;
	int face_to_index(int k) const;
};
#endif
