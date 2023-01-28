


#ifndef PLAYER_CLASS_DECLARATION
#define PLAYER_CLASS_DECLARATION



#include "../piece/piece.h"



class Player {
private:
    
    int color, score;

    vector <Piece *> deadPieces;

public:

    Player(int color);

    void insertDeadPiece(Piece *deadPiece);

    vector <string> getDeadPiecesNames() const;

};




#endif