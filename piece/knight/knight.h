




#ifndef KNIGHT_PIECE_CLASS_DECLARATION
#define KNIGHT_PIECE_CLASS_DECLARATION



#include "../piece.h"





class KnightPiece : public Piece {

public:

    KnightPiece(bool color, Position initialPosition);

    PiecePath pathTo(Position finalPosition) const;
};






#endif //  KNIGHT_PIECE_CLASS_DECLARATION