


#include "move_validator.h"
#include "../king_state/king_state.h"


MoveValidator::MoveValidator(Board *board, PositionValidator *positionValidator,
                PathValidator *pathValidator, KingState* &kingState) :
    board(board), positionValidator(positionValidator), pathValidator(pathValidator),
    kingState(kingState) {

}




Piece* MoveValidator::applyMove(Position startPosition, Position destinationPosition) {
 
    if (!validMove(startPosition, destinationPosition)) {
        throw GameException("Invalid move");
    }


    /*
        try moving
        check if king is going to die
        if so undo the move and throw error
        else return
    */


    Piece *deadPiece = board->movePiece(startPosition, destinationPosition);


    if (kingState->kingIsThreated()) {
        board->movePiece(destinationPosition, startPosition);
        board->setPiece(deadPiece);
        throw GameException("The king will die if this move is applied");
    }

    board->switchPlayerTurn();

    return deadPiece;
}








bool MoveValidator::validMove(Position startPosition, Position destinationPosition) const {
    if (!positionValidator->validPositions(startPosition, destinationPosition)) {
        return false;
    }

    PiecePath path = board->getSquare(startPosition)
                    ->getPiece()
                    ->pathTo(destinationPosition);

    
    if (!pathValidator->validPath(path)) {
        return false;
    }

    string pieceName = board->getSquare(startPosition)
                    ->getPiece()
                    ->getName();

    if (pieceName == "Pawn") {
        if (!pathValidator->pawnValidPath(startPosition, path)) {
            return false;
        }
    }

    return true;
}