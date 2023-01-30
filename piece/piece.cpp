

#include "piece.h"



Piece::Piece(string name, bool color, Position currentPosition) 
    : name(name), color(color), currentPosition(currentPosition) {

}



bool Piece::getColor () const {
    return color;
}


Position Piece::getXPosition () const {
    return currentPosition;
}


void Piece::setPosition (Position posistion) {
    currentPosition = posistion;
}


string Piece::getName() const {
    return name;
}