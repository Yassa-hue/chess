




#ifndef QUEEN_PIECE_CLASS_DECLARATION
#define QUEEN_PIECE_CLASS_DECLARATION



#include "../piece.h"






class QueenPiece : public Piece {

public:

    QueenPiece(bool color, int xPosition, int yPosition);

    bool isValidMove(int toXPosition, int toYPosition);
};






#endif // QUEEN_PIECE_CLASS_DECLARATION