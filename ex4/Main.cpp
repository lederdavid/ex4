#include "ex4headers.h" // this is the first line in main.cpp and the only required include for the main to work

int main()
{
	auto joker = std::numeric_limits<int>::min();
	list<Puzzle3dPiece<1>> pieces = {{0, 1, 1, 1, -1, -1}, {0, -1, 1, 1, 1, 1}};
	auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	auto some_pieces = groups.get({0, joker, 1, 1, joker, joker});
	for (auto piece_ptr : some_pieces)
	{
		std::cout << *piece_ptr << std::endl; // will print two pieces!
	}

	//list<Puzzle2dPiece<5>> pieces = {{0, 3, 2, -5}, {0, -2, 2, -5}};
	//auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	//// note that there is no & on the auto below (was in previous version)
	//auto some_pieces = groups.get({0, std::numeric_limits<int>::min(), 2, -5});
	//for (auto piece_ptr : some_pieces)
	//{
	//	std::cout << *piece_ptr << std::endl; // will print both pieces!
	//}
   //
	//list<Puzzle3dPiece<1>> pieces = { { 0, 1, 1, 1, -1, -1 },{ 0, -1, 1, 1, 1, 1 } };
	//auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	//// note that there is no & on the auto below (was in previous version)
	//auto some_pieces = groups.get({ 0, 1, 1, 1, 1, 1 });
	//for (auto piece_ptr : some_pieces) {
	//	std::cout << *piece_ptr << std::endl; // will print nothing!
	//}
   //
	//auto joker = std::numeric_limits<int>::min();
	//list<Puzzle3dPiece<1>> pieces = {{0, 1, 1, 1, -1, -1}, {0, -1, 1, 1, 1, 1}};
	//auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	//auto some_pieces = groups.get({0, joker, 1, 1, joker, joker});
	//for (auto piece_ptr : some_pieces)
	//{
	//	std::cout << *piece_ptr << std::endl; // will print two pieces!
	//}

	//vector<Puzzle2dPiece<5>> pieces = {{0, 3, 2, -5}, {0, -2, 2, -5}};
	//auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
	//auto some_pieces = groups.get({0, 3, 2, std::numeric_limits<int>::min()});
	//for (auto piece_ptr : some_pieces)
	//{
	//	std::cout << *piece_ptr << std::endl; // will print the first piece!
	//}
}
