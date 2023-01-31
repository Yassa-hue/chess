


#include "queen.h"



QueenPiece::QueenPiece(bool color, Position Position) 
    :Piece("Queen", color, Position) {

}



/*

    This function returns the path to the final point if possible.
    If the path is invalid according to the King's move it returns an empty path.

*/
vector<Position> QueenPiece::pathTo(Position finalPosition) const {


    vector <Position> path;


    PositionRelativeDirection finalPositionRelativeDirection 
                    = finalPosition.getDirectionFrom(currentPosition);

    if (finalPositionRelativeDirection == INVALID_RELATIVE_DIRECTION) {
        return {};
    }
    

    Position nextPathNode = Position(currentPosition);
    nextPathNode.moveOneStepInDirection(finalPositionRelativeDirection);


    while (!nextPathNode.isOutOfBoard()) {
        path.push_back(nextPathNode);

        if (nextPathNode == finalPosition) {
            return path;
        }

        nextPathNode.moveOneStepInDirection(finalPositionRelativeDirection);
    }

    // returning empty path
    return {};
}


