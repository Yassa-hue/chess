


#ifndef KING_STATE_CLASS_DECLARATION
#define KING_STATE_CLASS_DECLARATION


#include "../board/board.h"

class MoveValidator;


class KingState {
private:
    Board *board;
    MoveValidator* &moveValidator;
public:
    KingState(Board *board, MoveValidator* &moveValidator);

    bool kingIsThreated();

    bool currentPlayerIsCheckMated();
};







#endif // KING_STATE_CLASS_DECLARATION