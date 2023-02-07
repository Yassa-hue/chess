


#ifndef PAWN_PIECE_CLASS_DECLARATION
#define PAWN_PIECE_CLASS_DECLARATION



#include "../piece.h"








class PawnPiece : public Piece {

public:

    PawnPiece(bool color, Position Position);

    vector<Position> pathTo(Position finalPosition) const;
};






#endif // PAWN_PIECE_CLASS_DECLARATION