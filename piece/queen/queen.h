




#ifndef QUEEN_PIECE_CLASS_DECLARATION
#define QUEEN_PIECE_CLASS_DECLARATION



#include "../piece.h"





class QueenPiece : public Piece {

public:

    QueenPiece(bool color, Position initialPosition);

    PiecePath pathTo(Position finalPosition) const;
};






#endif // QUEEN_PIECE_CLASS_DECLARATION