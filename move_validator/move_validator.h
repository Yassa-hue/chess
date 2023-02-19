






#ifndef MOVE_VALIDATOR_CLASS_DECLARATION
#define MOVE_VALIDATOR_CLASS_DECLARATION

#include "../board/board.h"
#include "../position_validator/position_validator.h"
#include "../path_validator/path_validator.h"

class KingState;



class MoveValidator {
private:
    Board *board;
    PathValidator *pathValidator;
    PositionValidator *positionValidator;
    KingState* &kingState;

public:
    MoveValidator(Board *board, PositionValidator *positionValidator,
                PathValidator *pathValidator, KingState* &kingState);

    bool validMove(Position startPosition, Position destinationPosition) const;

    Piece* applyMove(Position startPosition, Position destinationPosition);
};







#endif // MOVE_VALIDATOR_CLASS_DECLARATION