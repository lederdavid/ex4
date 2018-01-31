#pragma once
#ifndef PUZZLE_GROUP_PIECES_H_INCLUDED
#define PUZZLE_GROUP_PIECES_H_INCLUDED
#include "PuzzleGroupBase.h"

/**
 * Recieve an iterator of pieces, initialize a puzzle-group and add pieces to it
 */
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

/**
 * override operator << to work as to_string()
 */
inline ostream& operator<<(ostream& lhs, const PuzzlePieceBase& rhs)
{
	vector<int> edges = rhs.get_edges();
	if (rhs._D == 2)
	{
		lhs << "{" << edges[0] << ", " << edges[1] << ", " << edges[2] << ", " << edges[3] << "}";
	}
	else
	{
		lhs << "{" << edges[0] << ", " << edges[1] << ", " << edges[2] << ", " << edges[3] << ", " << edges[4] << ", " <<
			edges[5] << "}";
	}
	return lhs;
}
#endif
