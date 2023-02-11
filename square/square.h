

#ifndef SQUARE_CLASS_DECLARATION
#define SQUARE_CLASS_DECLARATION

#include "../piece/piece.h"


#define EMPTY_SQUARE_ABBREVIATION '.'


class Square {
private:
    Piece *piece;

    Position position;
public:

    Square(Position position);

    Position getPosition () const;

    void setPiece(Piece *piece);

    void deletePiece();

    Piece *getPiece() const;
    
    bool isBusy() const;

    char getPrintingSymbol () const;
};




#endif