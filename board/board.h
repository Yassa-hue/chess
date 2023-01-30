


#ifndef BOARD_CLASS_DECLARATION
#define BOARD_CLASS_DECLARATION

#include "../square/square.h"
#include "../position_struct.h"

#define NO_CHECK 1
#define CHECK 2
#define CHECK_MATE 3


class Board {
private:
    vector <vector <Square *>> board;


public:
    
    void movePiece(Position fromPosition, Position toPosition, int playerColor);


    bool check(bool kingColor) const;
};




#endif