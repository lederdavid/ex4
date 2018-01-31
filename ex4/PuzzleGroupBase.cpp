#include "PuzzleGroupBase.h"

using namespace std;


PuzzleGroupBase::PuzzleGroupBase(int k, int d)
	: _k(k),
	  size(2 * k + 2),
	  _data(k, d)
{
}

PuzzleGroupBase::PuzzleGroupBase(PuzzleGroupBase&& other) noexcept
	: _k(other._k),
	  size(other.size),
	  _data(other._data)
{
}

PuzzleGroupBase::~PuzzleGroupBase()
{
	_data.free();
}

vector<PuzzlePieceBase*> PuzzleGroupBase::get(initializer_list<int> piece) const
{
	return _data.get(piece);
}

void PuzzleGroupBase::add(PuzzlePieceBase* piece) const
{
	_data.add(piece);
}
