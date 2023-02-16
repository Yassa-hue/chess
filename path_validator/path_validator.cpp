



#include "path_validator.h"


PathValidator::PathValidator(Board *board) : board(board) {

}





bool PathValidator::validPath(const PiecePath &piecePath) {
    // if the path is empty it is invlid
    if (piecePath.empty()) { 
        return false;
    }


    if (pathIsBlocked(piecePath)) {
        return false;
    }

    return true;
}





bool PathValidator::pathIsBlocked(const PiecePath &path) const {

    for (size_t i = 0; i+1 < path.size(); i++) {
        if (board->getSquare(path[i])->isBusy()) {
            return true;
        }
    }
    
    if (board->getSquare(path.back())->isBusy()) {
        if (!existOpponentPieceAtEndOfPath(path.back())) {
            return true;
        }
    }

    return false;

}



bool PathValidator::existOpponentPieceAtEndOfPath(const Position &endOfPath) const {
    const Square *endOfPathSquare = board->getSquare(endOfPath);
    
    if (!endOfPathSquare->isBusy()) {
        return false;
    }

    Piece *endOfPathPiece = endOfPathSquare->getPiece();

    if (endOfPathPiece == nullptr) {
        return false;
    }

    return (endOfPathPiece->getColor() != board->getCurrentPlayerColor());
}




bool PathValidator::pawnValidPath(const Position &startPosition, const PiecePath &pawnPath) const {
    if (startPosition.y == pawnPath.front().y) {
        return true;
    }

    return existOpponentPieceAtEndOfPath(pawnPath.back());
}