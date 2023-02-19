



#include "king_state.h"
#include "../move_validator/move_validator.h"


KingState::KingState(Board *board, MoveValidator* &moveValidator) :
    board(board), moveValidator(moveValidator) {

}





bool KingState::kingIsThreated () {
    Position currentKingPosition = board->getCurrentKingPosition();



    for (size_t x = 0; x < BOARD_SIZE; x++) {
        for (size_t y = 0; y < BOARD_SIZE; y++) {
            Position threatingPosition = Position(x, y);
            const Square *threatingSquare = board->getSquare(threatingPosition);

            board->switchPlayerTurn();
            
            if (!threatingSquare->isBusy()) {
                board->switchPlayerTurn();
                continue;
            }


            // if (threatingSquare->getPiece()->getColor() != boardcurrentPlayerColor) {
            //     switchPlayerTurn();
            //     continue;
            // }


            if (!moveValidator->validMove(threatingPosition, currentKingPosition)) {
                board->switchPlayerTurn();
                continue;
            }

            board->switchPlayerTurn();

            return true;
        }
    }

    return false;
    
}




bool KingState::currentPlayerIsCheckMated() {
    if (!kingIsThreated()) {
        return false;
    }

    Position startPosition(0, 0);



    while (!startPosition.isOutOfBoard()) {
        Position destinationPosition(0, 0);

        while (!destinationPosition.isOutOfBoard()) {
            if (!moveValidator->validMove(startPosition, destinationPosition)) {
                ++destinationPosition;
                continue;
            }

            Piece*deadPiece = board->movePiece(startPosition, destinationPosition);

            bool kingIsDead = kingIsThreated();

            board->movePiece(destinationPosition, startPosition);

            board->setPiece(deadPiece);

            if (!kingIsDead) {
                return false;
            }

            ++destinationPosition;
        }
        
        ++startPosition;
    }
    return true;
}