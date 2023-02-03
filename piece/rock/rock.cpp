


#include "rock.h"

RockPiece::RockPiece(bool color, Position Position)
    // Set the name of the piece according to the color.
    : Piece("Rock", color, Position){

}



bool RockPiece::isValidRelativeDirection(PositionRelativeDirection relativeDirection) const{
    if(relativeDirection == UP_RELATIVE_DIRECTION
    || relativeDirection == DOWN_RELATIVE_DIRECTION
    || relativeDirection == LEFT_RELATIVE_DIRECTION
    || relativeDirection == RIGHT_RELATIVE_DIRECTION) return true;
    return false;
}

/*

    This function returns the path to the final point if possible.
    If the path is invalid according to the King's move it returns an empty path.

*/
vector<Position> RockPiece::pathTo(Position finalPosition) const {
    PiecePath path;
    

    PositionRelativeDirection finalPositionRelativeDirection 
                    = currentPosition.getDirectionFrom(finalPosition);
    
    if (!isValidRelativeDirection(finalPositionRelativeDirection)) {
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


    return {};
}

