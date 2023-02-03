




#ifndef PIECE_PATH_CLASS_DECLARATION
#define PIECE_PATH_CLASS_DECLARATION

#include <iostream>
#include <vector>
#include "../position_struct.h"
#include "../board/board.h"


using namespace std;






class PiecePath {
private:
    vector <Position> steps;

    Position startPosition;

    bool isBlocked(const Board *board) const;

    bool existOpponentPieceAtEndOfPath(const Board *board) const ;

    bool pawnValidPath(const Board *board) const;

public:
    PiecePath(Position startPosition);

    void addStep(const Position &step);

    bool operator== (PiecePath piecePath);

    bool operator!= (PiecePath piecePath);

    bool operator+= (const Position &step);

    bool isValid(const Board *board) const;
};








#endif // PIECE_PATH_CLASS_DECLARATION