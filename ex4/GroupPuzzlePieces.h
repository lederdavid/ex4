#pragma once
#include "PuzzleGroupBase.h"

template <class iterator_type>

PuzzleGroupBase groupPuzzlePieces(iterator_type begin, iterator_type end)
{
	PuzzleGroupBase puzzle_group(begin->_K, begin->_D);
	for (iterator_type piece = begin; piece != end; ++piece)
	{
		puzzle_group.add(&(*piece));
	}
	return puzzle_group;
}
