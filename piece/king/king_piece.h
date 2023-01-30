


#ifndef KING_PIECE_CLASS_DECLARATION
#define KING_PIECE_CLASS_DECLARATION



#include "../piece.h"


// Board diminsion

#define BOARD_FIRST_X 0
#define BOARD_LAST_X 7
#define BOARD_FIRST_Y 0
#define BOARD_LAST_Y 7





class KingPiece : public Piece {

public:

    KingPiece(bool color, Position Position);

    vector<Position> pathTo(Position finalPosition) const;
};






#endif // KING_PIECE_CLASS_DECLARATION