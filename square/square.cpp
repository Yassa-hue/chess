




#include "square.h"


Square::Square(Position position) : position(position) {

}



Position Square::getPosition () const {
    return position;
}




void Square::setPiece(Piece *piece) {
    this->piece = piece;
}



void Square::deletePiece() {
    piece = nullptr;
}



Piece *Square::getPiece() const {
    return piece;
}




bool Square::isBusy() const {
    return (piece == nullptr);
}