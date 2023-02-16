






#include "board.h"


Board::Board() : currentPlayerColor(WHITE_COLOR), 
    whiteKingCurrentPosition(WHITE_KING_INITIAL_POSITION),
    blackKingCurrentPosition(BLACK_KING_INITIAL_POSITION) {
    createBoardSquares();
}


Board::Board(const vector <Piece*> whitePieces, const vector <Piece*> blackPieces) 
    : Board() {
    putPiecesOnBoard(whitePieces);
    putPiecesOnBoard(blackPieces);
}




void Board::putPiecesOnBoard (const vector <Piece*> pieces) {
    for (Piece *piece : pieces) {
        setPiece(piece);
    }
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





void Board::switchPlayerTurn() {
    if (currentPlayerColor == WHITE_COLOR) {
        currentPlayerColor = BLACK_COLOR;
    } else {
        currentPlayerColor = WHITE_COLOR;
    }
}




void Board::updateKingPosition(const Position &newPosition) {
    if (currentPlayerColor == WHITE_COLOR) {
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

            cout << square->getPrintingSymbol() << ' ';
        }

        cout<< endl;
        
    }
    
    
}






void Board::setPiece(Piece *piece) {
    if (piece == nullptr)
        return;
        
    getSquare(piece->getPosition())
    ->setPiece(piece);
}






void Board::createBoardSquares() {
    board = vector <vector <Square *>> (BOARD_SIZE, vector <Square *>(BOARD_SIZE, nullptr));
    
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



Position Board::getCurrentKingPosition() const {
    if (getCurrentPlayerColor() == WHITE_COLOR) {
        return whiteKingCurrentPosition;
    }

    return blackKingCurrentPosition;
}