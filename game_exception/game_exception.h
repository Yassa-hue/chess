



#ifndef GAME_EXCEPTION_CLASS
#define GAME_EXCEPTION_CLASS



#include <iostream>

using namespace std;


class GameException : exception{
private:
    string errMsg;
public:

    GameException(string errMsg);

    const string &getErrMsg() const;
};






#endif