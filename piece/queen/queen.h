




#ifndef QUEEN_PIECE_CLASS_DECLARATION
#define QUEEN_PIECE_CLASS_DECLARATION



#include "../piece.h"


typedef int PositionRelativeDirection;

#define RIGHT_RELATIVE_DIRECTION 1
#define UPPER_RIGHT_RELATIVE_DIRECTION 2
#define UP_RELATIVE_DIRECTION 3
#define UPPER_LEFT_RELATIVE_DIRECTION 4
#define LEFT_RELATIVE_DIRECTION 5
#define DOWN_LEFT_RELATIVE_DIRECTION 6
#define DOWN_RELATIVE_DIRECTION 7
#define DOWN_RIGHT_RELATIVE_DIRECTION 8
#define INVALID_RELATIVE_DIRECTION -1




class QueenPiece : public Piece {

public:

    QueenPiece(bool color, Position initialPosition);

    vector<Position> pathTo(Position finalPosition) const;
};






#endif // QUEEN_PIECE_CLASS_DECLARATION