



#ifndef COLORS_DECLERATION

#define COLORS_DECLERATION
#define WHIGHT_COLOR 1
#define BLACK_COLOR 0

#endif



#ifndef PIECE_CLASS_DECLARATION
#define PIECE_CLASS_DECLARATION




#include <iostream>
#include <vector>



using namespace std;





class Piece {
protected:

    bool color;


    string name;


    int xPosition, yPosition;


public:

    Piece(string name, bool color, int xPosition, int yPosition);

    virtual vector<pair<int, int>> pathTo(int xPosition, int yPosition) const;

    bool getColor () const;

    int getXPosition () const;

    int getYPosition () const;

    void setPosition (int x, int y);

    string getName() const;
};






#endif // PIECE_CLASS_DECLARATION