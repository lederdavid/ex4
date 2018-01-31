#pragma once
#include "Puzzle2dPiece.h"
#include "Puzzle3dPiece.h"
#include "PuzzleGroup2d.h"
#include "PuzzleGroup3d.h"

template <class iterator_type>

PuzzleGroupBase groupPuzzlePieces(iterator_type begin, iterator_type end)
{
	if (begin->_D == 2)
	{
		PuzzleGroup2d puzzle_group2d(begin->_K);
		for (iterator_type piece = begin; piece != end; ++piece)
		{
			puzzle_group2d.add(&(*piece));
		}
		return static_cast<PuzzleGroupBase>(puzzle_group2d);
	}
	PuzzleGroup3d puzzle_group3d(begin->_K);
	for (iterator_type piece = begin; piece != end; ++piece)
	{
		puzzle_group3d.add(&(*piece));
	}
	return static_cast<PuzzleGroupBase>(puzzle_group3d);
}