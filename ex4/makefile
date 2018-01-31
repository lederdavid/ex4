COMP = g++-5.3.0
#put all your object files here
OBJS = Main.o ex4headers.o GroupPuzzlePieces.o PuzzleGroupBase.o PuzzleGroupData.o PuzzlePieceBase.o   Puzzle2dPiece.o Puzzle3dPiece.o  
#The executable filename DON'T CHANGE
EXEC = ex4
CPP_COMP_FLAG = -std=c++14 -Wall -Wextra \
-Werror -pedantic-errors -DNDEBUG

$(EXEC): $(OBJS)
	$(COMP) $(OBJS) -o $@
#a rule for building a simple c++ source file
#use g++ -MM main.cpp to see dependencies
Main.o: Main.cpp ex4headers.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

ex4headers.o: ex4headers.h GroupPuzzlePieces.h  Puzzle2dPiece.h Puzzle3dPiece.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
	
GroupPuzzlePieces.o: GroupPuzzlePieces.h PuzzleGroupBase.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

PuzzleGroupBase.o: PuzzleGroupBase.h PuzzleGroupData.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
	
PuzzleGroupData.o: PuzzleGroupData.h PuzzlePieceBase.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

Puzzle2dPiece.h: Puzzle2dPiece.h PuzzlePieceBase.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

Puzzle3dPiece.h: Puzzle3dPiece.h PuzzlePieceBase.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp

PuzzlePieceBase.o: PuzzlePieceBase.cpp PuzzlePieceBase.h
	$(COMP) $(CPP_COMP_FLAG) -c $*.cpp
	
clean:
	rm -f $(OBJS) $(EXEC)