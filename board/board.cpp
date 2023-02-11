






#include "board.h"


Board::Board() : currentPlayerColor(WHIGHT_COLOR), 
    whiteKingCurrentPosition(WHITE_KING_INITIAL_POSITION),
    blackKingCurrentPosition(BLACK_KING_INITIAL_POSITION) {
    board = vector <vector <Square *>> (BOARD_SIZE, vector <Square *>(BOARD_SIZE, nullptr));
    createBoardSquares();
}



Piece* Board::applyMove(Position startPosition, Position destinationPosition) {
 
    if (!validMove(startPosition, destinationPosition)) {
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
        setPiece(deadPiece);
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






bool Board::validMove(Position startPosition, Position destinationPosition) const {
    if (!validPositions(startPosition, destinationPosition)) {
        //cout<< "errrrr1" << endl;
        return false;
    }

    PiecePath path = getSquare(startPosition)
                    ->getPiece()
                    ->pathTo(destinationPosition);

    
    if (!validPath(path)) {
        //cout<< "errrrr2" << endl;
        return false;
    }

    string pieceName = getSquare(startPosition)
                    ->getPiece()
                    ->getName();

    if (pieceName == "Pawn") {
        if (!pawnValidPath(startPosition, path)) {
            //cout<< "errrrr3" << endl;
            return false;
        }
    }

    return true;
}




bool Board::validPositions(Position startPosition, Position destinationPosition) const {
    
    if (startPosition.isOutOfBoard()) {
        //cout<< "errrrr31" << endl;
        return false;
    }

    if (destinationPosition.isOutOfBoard()) {
        //cout<< "errrrr32" << endl;
        return false;
    }


    if (!(getSquare(startPosition)->isBusy())) {
        //cout<< "errrrr33" << endl;
        return false;
    }

    Piece *movingPiece = getSquare(startPosition)->getPiece();

    if (movingPiece->getColor() != currentPlayerColor) {
        //cout<< "errrrr34" << endl;
        return false;
    }
    //cout<< "errrrr35" << endl;
    return true;
}








bool Board::validPath(const PiecePath &piecePath) const {
    // if the path is empty it is invlid
    if (piecePath.empty()) { 
        //cout<< "errrrrr11" << endl;
        return false;
    }


    if (pathIsBlocked(piecePath)) {
        //cout<< "errrrrr12" << endl;
        return false;
    }

    return true;
}






bool Board::pathIsBlocked(const PiecePath &path) const {

    for (size_t i = 0; i+1 < path.size(); i++) {
        if (getSquare(path[i])->isBusy()) {

            //cout<< "errrrrr13" << endl;
            return true;
        }
    }
    
    if (getSquare(path.back())->isBusy()) {
        if (!existOpponentPieceAtEndOfPath(path.back())) {
            //cout<< "errrrrr14" << endl;
            return true;
        }
    }

    return false;

}



bool Board::existOpponentPieceAtEndOfPath(const Position &endOfPath) const {
    Square *endOfPathSquare = getSquare(endOfPath);
    
    if (!endOfPathSquare->isBusy()) {

        //cout<< "errrrrr15" << endl;
        return false;
    }

    Piece *endOfPathPiece = endOfPathSquare->getPiece();

    if (endOfPathPiece == nullptr) {
        //cout<< "errrrrr16" << endl;
        return false;
    }

    //cout<< "end " << endOfPath.x << endl << endOfPath.y << endl;

    //cout<< "errrrrr17" << endl;

    //cout<< endOfPathPiece->getName() << endOfPathPiece->getColor() << currentPlayerColor << endl;

    return (endOfPathPiece->getColor() != currentPlayerColor);
}




bool Board::pawnValidPath(const Position &startPosition, const PiecePath &pawnPath) const {
    if (startPosition.y == pawnPath.front().y) {
        return true;
    }

    return existOpponentPieceAtEndOfPath(pawnPath.back());
}






bool Board::kingIsThreated () {
    Position currentKingPosition = 
        (currentPlayerColor == WHIGHT_COLOR ? 
            whiteKingCurrentPosition 
            : blackKingCurrentPosition);

    
//    int opponentPlayerColor =
//        (currentPlayerColor == WHIGHT_COLOR ?
//            BLACK_COLOR
//            : WHIGHT_COLOR);



    for (size_t x = 0; x < BOARD_SIZE; x++) {
        for (size_t y = 0; y < BOARD_SIZE; y++) {
            Position threatingPosition = Position(x, y);
            Square *threatingSquare = getSquare(threatingPosition);

            switchPlayerTurn();

            //cout<< "pos = " << threatingPosition.x << ' ' << threatingPosition.y << endl;

            
            if (!threatingSquare->isBusy()) {
                switchPlayerTurn();
                //cout<< "errrrrrr20" << endl;
                continue;
            }

            


            if (threatingSquare->getPiece()->getColor() != currentPlayerColor) {
                switchPlayerTurn();
                //cout<< "errrrrrr21" << endl;
                continue;
            }


            if (!validMove(threatingPosition, currentKingPosition)) {
                //cout<< "errrrrr4" << endl;
                switchPlayerTurn();
                continue;
            }

            switchPlayerTurn();

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
    cout<< "   ";
    for (char yCharCoordinate = 'A'; yCharCoordinate <= 'H'; yCharCoordinate++) {
        cout<< yCharCoordinate << ' ';
    }
    cout<< "\n\n";

    for (int xCoordinate = 0; xCoordinate < BOARD_SIZE; xCoordinate++) {
        cout<< xCoordinate << "  ";
        for (int yCoordinate = 0; yCoordinate < BOARD_SIZE; yCoordinate++) {
            

            Square *square = getSquare(Position(xCoordinate, yCoordinate));

            if (!square->isBusy()) {
                cout<< EMPTY_SQUARE_ABBREVIATION << ' ';
                continue;
            }

            Piece *piece = square->getPiece();

            cout<< piece->getPrintAbbreviation() << ' ';
        }

        cout<< endl;
        
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
            //cout<< startPosition.x << ' ' << startPosition.y << ' ' << destinationPosition.x << ' ' << destinationPosition.y << endl;
            if (!validMove(startPosition, destinationPosition)) {
                ++destinationPosition;
                continue;
            }

            Piece*deadPiece = movePiece(startPosition, destinationPosition);

            bool kingIsDead = kingIsThreated();

            movePiece(destinationPosition, startPosition);

            setPiece(deadPiece);

            if (!kingIsDead) {
                //cout<< "errrrrr30" << endl;
                return false;
            }

            ++destinationPosition;
        }
        
        ++startPosition;
    }
    return true;
}



void Board::setPiece(Piece *piece) {
    if (piece == nullptr)
        return;
    getSquare(piece->getPosition())
    ->setPiece(piece);
}






void Board::createBoardSquares() {
    for (size_t i = 0; i < BOARD_SIZE; i++) {
        for (size_t j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = new Square(Position(i, j));
        }
    }
}




Board::~Board() {
    for (size_t i = 0; i < BOARD_SIZE; i++) {
        for (size_t j = 0; j < BOARD_SIZE; j++) {
            delete board[i][j];
        }
    }
}