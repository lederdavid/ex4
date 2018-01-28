#include <list>
#include "Puzzle2dPiece.h"
#include "PuzzleGroup2d.h"
#include <algorithm>


//PuzzleGroup2d groupPuzzlePieces(const list<Puzzle2dPiece<5>>::iterator& begin, const list<Puzzle2dPiece<5>>::iterator& end);

int main()
{
	std::vector<Puzzle2dPiece<5>> pieces = { { 0, 3, 2, -5 },{ 0, -2, 2, -5 } };
	auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	// // note that there is no & on the auto below (was in previous version)
	auto some_pieces = groups.get({ 0, std::numeric_limits<int>::min(), 2, -5 });
	// for (auto piece_ptr : some_pieces) {
	// std::cout << *piece_ptr << std::endl; // will print both pieces!
	// }
	return 0;
}
