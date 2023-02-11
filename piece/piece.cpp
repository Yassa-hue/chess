

#include "piece.h"



Piece::Piece(string name, bool color, Position currentPosition) 
    : name(name), color(color), currentPosition(currentPosition) {

}



bool Piece::getColor () const {
    return color;
}


Position Piece::getPosition () const {
    return currentPosition;
}


void Piece::setPosition (Position posistion) {
    currentPosition = posistion;
}


string Piece::getName() const {
    return name;
}


char Piece::getPrintAbbreviation() const {

    if (getName() == "Knight") {
        if (getColor() == WHITE_COLOR) {
            return 'N';
        } else {
            return 'n';
        }
    }

    char printAbbreviation = getName().front();

    // if the piece is black convert from capital to small
    if (getColor() == BLACK_COLOR) {
        printAbbreviation = printAbbreviation - 'A' + 'a';
    }

    return printAbbreviation;
}