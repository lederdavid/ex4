#include "ex4headers.h" // this is the first line in main.cpp and the only required include for the main to work
#include <list>


int main() {
	list<Puzzle3dPiece<1>> pieces = { { 0, 1, 1, 1, -1, -1 },{ 0, -1, 1, 1, 1, 1 } };
	auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	// note that there is no & on the auto below (was in previous version)
	auto some_pieces = groups.get({ 0, 1, 1, 1, 1, 1 });
	for (auto piece_ptr : some_pieces) {
		std::cout << *piece_ptr << std::endl; // will print nothing!
	}
}
