


#ifndef BISHOP_PIECE_CLASS_DECLARATION
#define BISHOP_PIECE_CLASS_DECLARATION



#include "../piece.h"






class BishopPiece : public Piece {
private:
    bool isValidRelativeDirection(PositionRelativeDirection relativeDirection) const;
public:

    BishopPiece(bool color, Position Position);

    PiecePath pathTo(Position finalPosition) const;
};






#endif // BISHOP_PIECE_CLASS_DECLARATION