#include "ex4headers.h" // this is the first line in main.cpp and the only required include for the main to work
#include <list>

int main() {
	vector<Puzzle2dPiece<5>> pieces = { { 0, 3, 2, -5 },{ 0, -2, 2, -5 } };
	auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	auto& some_pieces = groups.get({ 0, 3, 2, std::numeric_limits<int>::min() });
	for (auto piece_ptr : some_pieces) {
		std::cout << *piece_ptr << std::endl; // will print the first piece!
	}
}