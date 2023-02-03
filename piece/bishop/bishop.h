


#ifndef BISHOP_PIECE_CLASS_DECLARATION
#define BISHOP_PIECE_CLASS_DECLARATION



#include "../piece.h"


// Board diminsion

#define BOARD_FIRST_X 0
#define BOARD_LAST_X 7
#define BOARD_FIRST_Y 0
#define BOARD_LAST_Y 7





class BishopPiece : public Piece {
private:
    bool isValidRelativeDirection(PositionRelativeDirection relativeDirection) const;
public:

    BishopPiece(bool color, Position Position);

    vector<Position> pathTo(Position finalPosition) const;
};






#endif // BISHOP_PIECE_CLASS_DECLARATION