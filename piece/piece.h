



#ifndef COLORS_DECLERATION

#define COLORS_DECLERATION
#define WHITE_COLOR 1
#define BLACK_COLOR 0

#endif



#ifndef PIECE_CLASS_DECLARATION
#define PIECE_CLASS_DECLARATION




#include <iostream>
#include <vector>
#include "../position_struct.h"


using namespace std;




typedef vector<Position> PiecePath;





class Piece {
protected:

    bool color;


    string name;


    Position currentPosition;


public:

    Piece(string name, bool color, Position currentPosition);

    virtual PiecePath pathTo(Position finalPosition) const = 0;

    bool getColor () const;

    Position getPosition () const;

    void setPosition (Position posistion);

    string getName() const;

    char getPrintingAbbreviation() const;

    virtual ~Piece() = default;
};






#endif // PIECE_CLASS_DECLARATION