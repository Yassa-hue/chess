

#include "piece_path.h"


PiecePath::PiecePath(Position startPostion) 
    : startPosition(startPosition), steps (vector<Position> ()) {

}


void PiecePath::addStep(const Position &step) {
    steps.push_back(step);
}


bool PiecePath::operator!= (PiecePath piecePath) {
    if (startPosition != piecePath.startPosition) {
        return true;
    }
    
    if (steps.size() != piecePath.steps.size()) {
        return true;
    }
    
    for (size_t i = 0; i < steps.size(); i++) {
        if (steps[i] != piecePath.steps[i]) {
            return true;
        }
    }
    
}



bool PiecePath::operator== (PiecePath piecePath) {
    return !PiecePath::operator!=(piecePath);
}




bool PiecePath::operator+= (const Position &step) {
    addStep(step);
}




bool PiecePath::isValid(const Board *board) const {
     // if the path is empty it is invlid
    if (steps.empty()) { 
        return false;
    }


    if (isBlocked(board)) {
        return false;
    }


    // pawn
}


bool PiecePath::isBlocked(const Board *board) const {
    for (size_t i = 0; i+1 < steps.size(); i++) {
        if (board->getSquare(steps[i])->isBusy()) {
            return false;
        }
    }
    
    if (!board->getSquare(steps.back())->isBusy()
        && !existOpponentPieceAtEndOfPath(board)) {
        return false;
    }

    return true;
}


bool PiecePath::existOpponentPieceAtEndOfPath(const Board *board) const {
    Piece *endOfPathPiece = board->getSquare(steps.back())->getPiece(); 
    
    if (endOfPathPiece == nullptr) {
        return false;
    }

    return (endOfPathPiece->getColor() != board->getCurrentPlayerColor());
}


bool PiecePath::pawnValidPath(const Board *board) const {
    if (startPosition.y == steps.front().y) {
        return true;
    }

    return existOpponentPieceAtEndOfPath(board);
}

