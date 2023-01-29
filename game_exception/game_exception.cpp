



#include "game_exception.h"


GameException::GameException(string errMsg) : exception(), errMsg(errMsg) {

}


const string &GameException::getErrMsg() const {
    return errMsg;
}