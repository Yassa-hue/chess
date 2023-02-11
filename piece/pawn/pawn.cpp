


#include "pawn.h"


PawnPiece::PawnPiece(bool color, Position Position)
    // Set the name of the piece according to the color.
    : Piece("Pawn", color, Position){

}




/*

    This function returns the path to the final point if possible.
    If the path is invalid according to the King's move it returns an empty path.

*/
PiecePath PawnPiece::pathTo(Position finalPosition) const {

    Position currentPosition = getPosition();
    if(color == WHITE_COLOR){

        // special case if I'm in the second row
        // you can move 2 steps instead of 1
        if(currentPosition.x == 1){
            if(finalPosition.x == 3 && currentPosition.y == finalPosition.y) return {Position(2 , currentPosition.y) ,finalPosition};
        }
        if(finalPosition.x == currentPosition.x + 1 && (
            finalPosition.y == currentPosition.y || 
            finalPosition.y == currentPosition.y + 1 ||
            finalPosition.y == currentPosition.y - 1
        ))  return {finalPosition};
        
    }else{
        // special case if I'm in the second row
        // you can move 2 steps instead of 1
        if(currentPosition.x == 6){
            if(finalPosition.x == 4 && currentPosition.y == finalPosition.y) return {Position(5 , currentPosition.y) ,finalPosition};;
        }
        if(finalPosition.x == currentPosition.x - 1 && (
            finalPosition.y == currentPosition.y || 
            finalPosition.y == currentPosition.y + 1 ||
            finalPosition.y == currentPosition.y - 1
        )) return {finalPosition};
        
        
    }
    return {};
}

