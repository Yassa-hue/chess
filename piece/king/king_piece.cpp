


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
    

    PositionRelativeDirection finalPositionRelativeDirection 
                    = currentPosition.getDirectionFrom(finalPosition);
    
    if (finalPositionRelativeDirection == INVALID_RELATIVE_DIRECTION) {
        return {};
    }

    Position nextPathNode = Position(currentPosition);
    nextPathNode.moveOneStepInDirection(finalPositionRelativeDirection);

    resultPath.push_back(nextPathNode);

    if (nextPathNode == finalPosition) {
        return resultPath;
    }


    return {};
}

