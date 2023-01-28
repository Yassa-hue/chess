


#ifndef BOARD_CLASS_DECLARATION
#define BOARD_CLASS_DECLARATION

#include "../square/square.h"

#define NO_CHECK 1
#define CHECK 2
#define CHECK_MATE 3


class Board {
private:
    vector <vector <Square *>> board;


public:
    
    void movePiece(int fromXPosition, int fromYPosition, int toXPosition, int toYPosition, int playerColor);


    bool check(bool kingColor) const;
};




#endif