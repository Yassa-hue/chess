



#ifndef GAME_CLASS_DECLARATION
#define GAME_CLASS_DECLARATION

#include "../board/board.h"
#include "../piece/king/king_piece.h"
#include "../piece/queen/queen.h"
#include "../piece/bishop/bishop.h"
#include "../piece/knight/knight.h"
#include "../piece/rock/rock.h"
#include "../piece/pawn/pawn.h"
#include "../position_validator/position_validator.h"
#include "../path_validator/path_validator.h"
#include "../move_validator/move_validator.h"
#include "../king_state/king_state.h"



#define SCREEN_SIZE 100

#define EXIT_CODE -1



#define PAWNS_NUM 8
#define WHITE_PAWNS_X_COORDINATE 1 
#define BLACK_PAWNS_X_COORDINATE 6



#define WHITE_QUEEN_INITIAL_POSITION Position(0, 4)
#define BLACK_QUEEN_INITIAL_POSITION Position(7, 3)


#define LEFT_WHITE_BISHOP_INITIAL_POSITION Position(0, 2)
#define RIGHT_WHITE_BISHOP_INITIAL_POSITION Position(0, 5)

#define LEFT_BLACK_BISHOP_INITIAL_POSITION Position(7, 2)
#define RIGHT_BLACK_BISHOP_INITIAL_POSITION Position(7, 5)


#define LEFT_WHITE_NIGHT_INITIAL_POSITION Position(0, 1)
#define RIGHT_WHITE_NIGHT_INITIAL_POSITION Position(0, 6)

#define LEFT_BLACK_NIGHT_INITIAL_POSITION Position(7, 1)
#define RIGHT_BLACK_NIGHT_INITIAL_POSITION Position(7, 6)


#define LEFT_WHITE_ROCK_INITIAL_POSITION Position(0, 0)
#define RIGHT_WHITE_ROCK_INITIAL_POSITION Position(0, 7)


#define LEFT_BLACK_ROCK_INITIAL_POSITION Position(7, 0)
#define RIGHT_BLACK_ROCK_INITIAL_POSITION Position(7, 7)



// Pawn upgrading choices
#define UPGRADE_PAWN_TO_QUEEN 1
#define UPGRADE_PAWN_TO_BISHOP 2
#define UPGRADE_PAWN_TO_KNIGHT 3
#define UPGRADE_PAWN_TO_ROCK 4




class Game {
private:
    Board *board;
    PositionValidator *positionValidator;
    PathValidator *pathValidator;
    MoveValidator *moveValidator;
    KingState *kingState;

    vector <Piece*> whitePieces, blackPieces, deadBlackPieces, deadWhitePieces;
    

    void createPieces();

    void printDeadPieces();

    int convertYCoordinateToInt(char yCoordinate);

    void clearScreen() const;

    void printPawnUpgradingChoices() const;

    void upgradePawn(Position newPiecePosition, int newPieceColor);


public:

    Game();
    
    void play();

    ~Game();

};




#endif