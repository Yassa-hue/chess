


#ifndef KING_PIECE_CLASS_DECLARATION
#define KING_PIECE_CLASS_DECLARATION



#include "../piece.h"








class KingPiece : public Piece {

public:

    KingPiece(bool color, Position Position);

    vector<Position> pathTo(Position finalPosition) const;
};






#endif // KING_PIECE_CLASS_DECLARATION