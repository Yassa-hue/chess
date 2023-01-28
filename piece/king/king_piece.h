


#ifndef KING_PIECE_CLASS_DECLARATION
#define KING_PIECE_CLASS_DECLARATION



#include "../piece.h"






class KingPiece : public Piece {

public:

    KingPiece(bool color, int xPosition, int yPosition);

    bool isValidMove(int toXPosition, int toYPosition);
};






#endif // KING_PIECE_CLASS_DECLARATION