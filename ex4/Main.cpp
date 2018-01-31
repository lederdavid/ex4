#include <list>
#include "Puzzle2dPiece.h"
#include "PuzzleGroup2d.h"
#include <algorithm>


//PuzzleGroup2d groupPuzzlePieces(const list<Puzzle2dPiece<5>>::iterator& begin, const list<Puzzle2dPiece<5>>::iterator& end);

int main() {
	vector<Puzzle2dPiece<5>> pieces = { { 0, 3, 2, -5 },{ 0, -2, 2, -5 } };
	auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	auto some_pieces = groups.get({ 0, 4, 2, std::numeric_limits<int>::min() });
	for (auto piece_ptr : some_pieces) {
		std::cout << *piece_ptr << std::endl; // will print the first piece!
	}
}
