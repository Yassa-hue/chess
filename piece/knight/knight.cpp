


#include "knight.h"

#define  POSSIBLE_VALID_MOVES 8

KnightPiece::KnightPiece(bool color, Position Position)
    // Set the name of the piece according to the color.
    : Piece("Knight", color, Position){

}




/*

    This function returns the path to the final point if possible.
    If the path is invalid according to the King's move it returns an empty path.

*/
PiecePath KnightPiece::pathTo(Position finalPosition) const {

    int horizontalMove[] = {-2,-2,2,2,-1,-1,1,1};
    int verticalMove[] = {1,-1,1,-1,2,-2,2,-2};

    for(int move = 0; move < POSSIBLE_VALID_MOVES; move++){
        int newXPosition = getXPosition().x + horizontalMove[move];
        int newYPosition = getXPosition().y + verticalMove[move];
        Position newPosition(newXPosition , newYPosition);
        if(newPosition == finalPosition) return {finalPosition};
    }
    return {};
}

