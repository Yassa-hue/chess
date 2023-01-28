



#ifndef GAME_CLASS_DECLARATION
#define GAME_CLASS_DECLARATION


#include "../player/player.h"
#include "../board/board.h"



class Game {
private:
    Player *whitePlayer, *blackPlayer;

    Board *board;

    vector <Piece*> pieces;
public:

    Game();

    ~Game();

};




#endif