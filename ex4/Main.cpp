#include "ex4headers.h" // this is the first line in main.cpp and the only required include for the main to work
#include <list>


int main() {
	auto joker = std::numeric_limits<int>::min();
	list<Puzzle3dPiece<1>> pieces = { { 0, 1, 1, 1, -1, -1 },{ 0, -1, 1, 1, 1, 1 } };
	auto& groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	auto some_pieces = groups.get({ 0, joker, 1, 1, joker, joker });
	for (auto piece_ptr : some_pieces) {
		std::cout << *piece_ptr << std::endl; // will print two pieces!
	}
}