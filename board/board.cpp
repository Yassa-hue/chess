






#include "board.h"


Board::Board() : currentPlayerColor(WHIGHT_COLOR), 
    whiteKingCurrentPosition(WHITE_KING_INITIAL_POSITION),
    blackKingCurrentPosition(BLACK_KING_INITIAL_POSITION) {
    board = vector <vector <Square *>> (BOARD_SIZE, vector <Square *>(BOARD_SIZE, nullptr));
}



Piece* Board::applyMove(Position startPosition, Position destinationPosition) {

    if (!validMove(startPosition, destinationPosition, currentPlayerColor)) {
        throw GameException("Invalid move");
    }


    /*
        try moving
        check if king is going to die
        if so undo the move and throw error
        else return
    */


    Piece *deadPiece = movePiece(startPosition, destinationPosition);
    

    if (kingIsThreated()) {
        movePiece(destinationPosition, startPosition);
        throw GameException("The king will die if this move is applied");
    }

    switchPlayerTurn();

    return deadPiece;
}




Piece* Board::movePiece(Position startPosition, Position destinationPosition) {
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

    return deadPiece;
}






bool Board::validMove(Position startPosition, Position destinationPosition, int movingPlayerColor) const {
    if (!validPositions(startPosition, destinationPosition, movingPlayerColor)) {
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




bool Board::validPositions(Position startPosition, Position destinationPosition, int movingPlayerColor) const {
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

    if (movingPiece->getColor() != movingPlayerColor) {
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






bool Board::kingIsThreated () const {
    Position currentKingPosition = 
        (currentPlayerColor == WHIGHT_COLOR ? 
            whiteKingCurrentPosition 
            : blackKingCurrentPosition);

    
    int opponentPlayerColor = 
        (currentPlayerColor == WHIGHT_COLOR ? 
            BLACK_COLOR 
            : WHIGHT_COLOR);


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

            if (!validMove(threatingPosition, currentKingPosition, opponentPlayerColor)) {
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




int Board::getCurrentPlayerColor() const {
    return currentPlayerColor;
}


void Board::printBoard() {
    // print y coordinates in char
    cout << "   ";
    for (char yCharCoordinate = 'A'; yCharCoordinate <= 'G'; yCharCoordinate++) {
        cout << yCharCoordinate << ' ';
    }
    cout << "\n\n";

    for (int xCoordinate = 0; xCoordinate < BOARD_SIZE; xCoordinate++) {
        cout << xCoordinate << "  ";
        for (int yCoordinate = 0; yCoordinate < BOARD_SIZE; yCoordinate++) {
            

            Square *square = getSquare(Position(xCoordinate, yCoordinate));

            if (square->isBusy()) {
                cout << EMPTY_SQUARE_ABBREVIATION << ' ';
                continue;
            }

            Piece *piece = square->getPiece();

            cout << piece->getPrintAbbreviation() << ' ';
        }

        cout << endl;
        
    }
    
    
}





bool Board::currentPlayerIsCheckMated() {

    if (!kingIsThreated()) {
        return false;
    }

    Position startPosition(0, 0);

    while (!startPosition.isOutOfBoard()) {
        Position destinationPosition(0, 0);

        while (!destinationPosition.isOutOfBoard()) {
            if (!validMove(startPosition, destinationPosition, currentPlayerColor)) {
                continue;
            }

            movePiece(startPosition, destinationPosition);

            bool kingIsDead = kingIsThreated();

            movePiece(destinationPosition, startPosition);

            if (kingIsDead) {
                return true;
            }

            ++destinationPosition;
        }
        
        ++startPosition;
    }
    
    return false;
}



void Board::setPiece(Piece *piece) {
    getSquare(piece->getPosition())
    ->setPiece(piece);
}