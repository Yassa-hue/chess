


#ifndef BOARD_CLASS_DECLARATION
#define BOARD_CLASS_DECLARATION

#include "../square/square.h"
#include "../position_struct.h"
#include "../game_exception/game_exception.h"

class BoardUnitTest;

#define NO_CHECK 1
#define CHECK 2
#define CHECK_MATE 3


#define WHITE_KING_INITIAL_POSITION Position(0, 3)
#define BLACK_KING_INITIAL_POSITION Position(7, 4)


class Board {
private:
    int currentPlayerColor;

    Position whiteKingCurrentPosition, blackKingCurrentPosition; 

    vector <vector <Square *>> board;

    bool validMove(Position startPosition, Position destinationPosition) const;

    bool validPositions(Position startPosition, Position destinationPosition) const ;

    bool validPath(const PiecePath &piecePath) const ;

    bool pathIsBlocked(const PiecePath &path) const;

    bool existOpponentPieceAtEndOfPath(const Position &endOfPath) const ;

    bool pawnValidPath(const Position &startPosition, const PiecePath &pawnPath) const;

    bool kingDieIfPieceMoved(const Position &movingPiecePosition) const ;

    bool kingIsThreated() const;

    void switchPlayerTurn();

    void updateKingPosition(const Position &newPosition);

    Square *getSquare(const Position &squarePosition) const;



public:

    friend BoardUnitTest;

    Board();
    
    Piece* movePiece(Position startPosition, Position destinationPosition);

    void setPiece(Piece *piece);
};




#endif // BOARD_CLASS_DECLARATION