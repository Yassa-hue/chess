


#ifndef ROCK_PIECE_CLASS_DECLARATION
#define ROCK_PIECE_CLASS_DECLARATION



#include "../piece.h"


// Board diminsion

#define BOARD_FIRST_X 0
#define BOARD_LAST_X 7
#define BOARD_FIRST_Y 0
#define BOARD_LAST_Y 7





class RockPiece : public Piece {
private:
    bool isValidRelativeDirection(PositionRelativeDirection relativeDirection) const;
public:

    RockPiece(bool color, Position Position);

    vector<Position> pathTo(Position finalPosition) const;
};






#endif // ROCK_PIECE_CLASS_DECLARATION