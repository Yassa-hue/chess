


#include "king_piece.h"

KingPiece::KingPiece(bool color, int xPosition, int yPosition) 
    // Set the name of the piece according to the color.
    : Piece((color == WHIGHT_COLOR ? "Whight king" : "Black king"), color, xPosition, yPosition){

}




/*

    This function returns the path to the final point (x, y) if possible.
    If the path is invalid according to the King's move it returns an empty path.

*/
vector<pair<int, int>> KingPiece::pathTo(int finalXPosition, int finalYPosition) const {
    vector<pair<int, int>> resultPath;
    

    if (abs(finalXPosition - xPosition <= 1)
        && abs(finalYPosition - xPosition <= 1)
        && (finalXPosition != xPosition || finalYPosition != yPosition)) {
            resultPath.push_back({finalXPosition, finalYPosition});
        }


    return resultPath;
}

