
#ifndef GAME_EXCEPTION_CLASS_DECLARATION
#define GAME_EXCEPTION_CLASS_DECLARATION




#include <iostream>



using namespace std;


class GameException : public exception {
protected:

    string errMsg;


public:

    GameException(string errMsg) : exception(), errMsg(errMsg) {

    };


    const string &getErrMsg () const {
        return errMsg;
    } 

};






#endif // GAME_EXCEPTION_CLASS_DECLARATION