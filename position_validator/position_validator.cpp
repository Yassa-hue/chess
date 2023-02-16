


#include "position_validator.h"


PositionValidator::PositionValidator(Board *board) : board(board) {

}




bool PositionValidator::validPositions(Position startPosition, Position destinationPosition) const {
    if (startPosition.isOutOfBoard()) {
        return false;
    }

    if (destinationPosition.isOutOfBoard()) {
        return false;
    }


    if (!(board->getSquare(startPosition)->isBusy())) {
        return false;
    }

    Piece *movingPiece = board->getSquare(startPosition)->getPiece();

    if (movingPiece->getColor() != board->getCurrentPlayerColor()) {
        return false;
    }
    return true;
}





bool PositionValidator::isUpgradingPosition(Position destinationPosition) const {
    /*
        Position is upgrading if there is pawn at this position 
        and the pawn is at the end of its journey accourding to its color. 
    */
    
    Piece *piece= board->getSquare(destinationPosition)->getPiece();
    string pieceName= piece->getName();
    
    if(pieceName =="Pawn" && (destinationPosition.x==BOARD_FIRST_X||destinationPosition.x==BOARD_LAST_X)) {
        return true;
    }
    
    return false;
    
}