//#include "PuzzleGroup2d.h"



//template <int T>
//vector<PuzzleGroup2d*> PuzzleGroup2d::get(Puzzle2dPiece<T> piece)
//{
//	vector<PuzzleGroup2d*> result;
//	const int index_a = piece._edges[0] == std::numeric_limits<int>::min() ? 50 * 2 + 1 : piece._edges[0] + ARRAY_FACTOR;
//	add_without_duplicates(result, _a[index_a]);
//
//
//	return result;
//}
//
//
//void PuzzleGroup2d<T>::add_without_duplicates(const vector<PuzzleGroup2d*>& result,
//                                           const std::vector<PuzzleGroup2d*>& puzzle_group_2_ds)
//{
//	for (Puzzle2dPiece<T> piece : puzzle_group_2_ds)
//	{
//		if (std::find(result.begin(), result.end(), piece) != result.end())
//		{
//			continue;
//		}
//		else
//		{
//			result.push_back(piece);
//		}
//	}
//}
