

#ifndef SQUARE_CLASS_DECLARATION
#define SQUARE_CLASS_DECLARATION

#include "../piece/piece.h"


class Square {
private:
    Piece *piece;
    int xPosition, yPosition;
public:

    Square(int xPosition, int yPosition);

    int getXPosition () const;

    int getYPosition () const;

    void setPiece(Piece *piece);

    void deletePiece();

    Piece *getPiece() const;
    
    bool isBusy() const;
};




#endif