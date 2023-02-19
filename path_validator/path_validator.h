



#ifndef PATH_VALIDATOR_CLASS_DECLARATION
#define PATH_VALIDATOR_CLASS_DECLARATION

#include "../board/board.h"



class PathValidator {
private:
    Board *board;

    bool pathIsBlocked(const PiecePath &path) const;

    bool existOpponentPieceAtEndOfPath(const Position &endOfPath) const ;

public:
    PathValidator(Board *board);

    bool validPath(const PiecePath &piecePath);

    bool pawnValidPath(const Position &startPosition, const PiecePath &pawnPath) const;

};







#endif // PATH_VALIDATOR_CLASS_DECLARATION