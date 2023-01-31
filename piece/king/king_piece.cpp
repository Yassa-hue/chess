


#include "king_piece.h"

KingPiece::KingPiece(bool color, Position Position)
    // Set the name of the piece according to the color.
    : Piece("King", color, Position){

}




/*

    This function returns the path to the final point if possible.
    If the path is invalid according to the King's move it returns an empty path.

*/
vector<Position> KingPiece::pathTo(Position finalPosition) const {
    vector<Position> resultPath;
    

    if (abs(finalPosition.x - currentPosition.x) <= 1
        && abs(finalPosition.y - currentPosition.y) <= 1
        && (finalPosition.x != currentPosition.x || finalPosition.y != currentPosition.y)) {
            resultPath.push_back(finalPosition);
        }


    return resultPath;
}

