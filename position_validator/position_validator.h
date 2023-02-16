



#ifndef POSITION_VALIDATOR_CLASS_DECLARATION
#define POSITION_VALIDATOR_CLASS_DECLARATION


#include "../board/board.h"


class PositionValidator {
private:
    Board *board;
public:
    PositionValidator(Board *board);

    bool validPositions(Position startPosition, Position destinationPosition) const;

    bool isUpgradingPosition(Position destinationPosition) const;
};







#endif // POSITION_VALIDATOR_CLASS_DECLARATION