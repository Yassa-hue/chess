






#include "board.h"


Board::Board() : currentPlayerColor(WHIGHT_COLOR), 
    whiteKingCurrentPosition(WHITE_KING_INITIAL_POSITION),
    blackKingCurrentPosition(BLACK_KING_INITIAL_POSITION) {
    board = vector <vector <Square *>> (BOARD_SIZE, vector <Square *>(BOARD_SIZE, nullptr));
}



Piece* Board::movePiece(Position startPosition, Position destinationPosition) {

    if (!validMove(startPosition, destinationPosition)) {
        throw GameException("Invalid move");
    }

    if (kingDieIfPieceMoved(startPosition)) {
        throw GameException("The king will die if this piece moves");
    }
    
    Square *startSquare = getSquare(startPosition), 
            *destinationSquare = getSquare(destinationPosition); 

    Piece *movingPiece = startSquare->getPiece(),
            *deadPiece = destinationSquare->getPiece();


    startSquare->deletePiece();
    movingPiece->setPosition(destinationPosition);
    destinationSquare->setPiece(movingPiece);

    if (movingPiece->getName() == "King") {
        updateKingPosition(destinationPosition);
    }

    switchPlayerTurn();

    return deadPiece;
}






bool Board::validMove(Position startPosition, Position destinationPosition) const {
    if (!validPositions(startPosition, destinationPosition)) {
        return false;
    }

    PiecePath path = getSquare(startPosition)
                    ->getPiece()
                    ->pathTo(destinationPosition);

    
    if (!validPath(path)) {
        return false;
    }

    string pieceName = getSquare(startPosition)
                    ->getPiece()
                    ->getName();

    if (pieceName == "Pawn") {
        if (!pawnValidPath(startPosition, path)) {
            return false;
        }
    }

    return true;
}




bool Board::validPositions(Position startPosition, Position destinationPosition) const {
    if (startPosition.isOutOfBoard()) {
        return false;
    }

    if (destinationPosition.isOutOfBoard()) {
        return false;
    }

    if (!getSquare(startPosition)->isBusy()) {
        return false;
    }

    Piece *movingPiece = getSquare(startPosition)->getPiece();

    if (movingPiece->getColor() != currentPlayerColor) {
        return false;
    }

    return true;
}








bool Board::validPath(const PiecePath &piecePath) const {
    // if the path is empty it is invlid
    if (piecePath.empty()) { 
        return false;
    }


    if (pathIsBlocked(piecePath)) {
        return false;
    }

    return true;
}






bool Board::pathIsBlocked(const PiecePath &path) const {

    for (size_t i = 0; i+1 < path.size(); i++) {
        if (getSquare(path[i])->isBusy()) {
            return false;
        }
    }
    
    if (!getSquare(path.back())->isBusy()
        && !existOpponentPieceAtEndOfPath(path.back())) {
        return false;
    }

    return true;

}



bool Board::existOpponentPieceAtEndOfPath(const Position &endOfPath) const {
    Square *endOfPathSquare = getSquare(endOfPath);
    
    if (!endOfPathSquare->isBusy()) {
        return false;
    }

    Piece *endOfPathPiece = endOfPathSquare->getPiece();

    if (endOfPathPiece == nullptr) {
        return false;
    }

    return (endOfPathPiece->getColor() != currentPlayerColor);
}




bool Board::pawnValidPath(const Position &startPosition, const PiecePath &pawnPath) const {
    if (startPosition.y == pawnPath.front().y) {
        return true;
    }

    return existOpponentPieceAtEndOfPath(pawnPath.back());
}





bool Board::kingDieIfPieceMoved(const Position &movingPiecePosition) const {
    
    Square *pieceSquare = getSquare(movingPiecePosition);

    Piece *movingPiece = pieceSquare->getPiece();
    
    pieceSquare->deletePiece();

    bool kingWouldDie = kingIsThreated();

    pieceSquare->setPiece(movingPiece);

    return kingWouldDie;

}



bool Board::kingIsThreated () const {
    Position currentKingPosition = 
        (currentPlayerColor == WHIGHT_COLOR ? 
            whiteKingCurrentPosition 
            : blackKingCurrentPosition);


    for (size_t x = 0; x < BOARD_SIZE; x++) {
        for (size_t y = 0; y < BOARD_SIZE; y++) {
            Position threatingPosition = Position(x, y);
            Square *threatingSquare = getSquare(threatingPosition);

            if (!threatingSquare->isBusy()) {
                continue;
            }

            if (threatingSquare->getPiece()->getColor() == currentPlayerColor) {
                continue;
            }

            if (!validMove(threatingPosition, currentKingPosition)) {
                continue;
            }

            return true;
        }
    }

    return false;
    
}





void Board::switchPlayerTurn() {
    if (currentPlayerColor == WHIGHT_COLOR) {
        currentPlayerColor = BLACK_COLOR;
    } else {
        currentPlayerColor = WHIGHT_COLOR;
    }
}




void Board::updateKingPosition(const Position &newPosition) {
    if (currentPlayerColor == WHIGHT_COLOR) {
        whiteKingCurrentPosition = newPosition;
    } else {
        blackKingCurrentPosition = newPosition;
    }
}





Square *Board::getSquare(const Position &squarePosition) const {
    return board[squarePosition.x][squarePosition.y];
}