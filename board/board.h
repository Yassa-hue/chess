


#ifndef BOARD_CLASS_DECLARATION
#define BOARD_CLASS_DECLARATION

#include "../square/square.h"
#include "../position_struct.h"
#include "../game_exception/game_exception.h"




#define WHITE_KING_INITIAL_POSITION Position(0, 3)
#define BLACK_KING_INITIAL_POSITION Position(7, 4)


class Board {
private:
    int currentPlayerColor;

    Position whiteKingCurrentPosition, blackKingCurrentPosition; 

    vector <vector <Square *>> board;

    void createBoardSquares ();

    void putPiecesOnBoard (const vector <Piece*> pieces);

    // Empty constructor used for testing
    Board();

public:

    Board(const vector <Piece*> whitePieces, const vector <Piece*> blackPieces);

    Piece* movePiece(Position startPosition, Position destinationPosition);

    Square *getSquare(const Position &squarePosition) const;

    void switchPlayerTurn();

    void setPiece(Piece *piece);

    void updateKingPosition(const Position &newPosition);

    void printBoard();

    int getCurrentPlayerColor() const;

    Position getCurrentKingPosition() const;

    ~Board();
};




#endif // BOARD_CLASS_DECLARATION