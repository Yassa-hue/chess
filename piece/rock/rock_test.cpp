
#include "../piece_test.h"
#include "rock.h"


int main() {

    vector <PieceTestCase> testCases = {
        PieceTestCase("invalid test" , 1 , {Position(4, 4) , Position(5,5)} , 
        {}),

        PieceTestCase("invalid test" , 2 , {Position(4, 4) , Position(6,6)} , 
        {}),

        PieceTestCase("invalid test" , 3 , {Position(4, 4) , Position(7,7)} , 
        {}),

        PieceTestCase("invalid test" , 4 , {Position(4, 4) , Position(5,3)} , 
        {}),

        PieceTestCase("invalid test" , 5 , {Position(4, 4) , Position(6,2)} , 
        {}),

        PieceTestCase("invalid test" , 6 , {Position(4, 4) , Position(7,1)} , 
        {}),

        PieceTestCase("invalid test" , 7 , {Position(4, 4) , Position(3,3)} , 
        {}),

        PieceTestCase("invalid test" , 8 , {Position(4, 4) , Position(2,2)} , 
        {}),

        PieceTestCase("invalid test" , 9 , {Position(4, 4) , Position(1,1)} , 
        {}),

        PieceTestCase("invalid test" , 10 , {Position(4, 4) , Position(3,5)} , 
        {}),

        PieceTestCase("invalid test" , 11 , {Position(4, 4) , Position(2,6)} , 
        {}),

        PieceTestCase("invalid test" , 12 , {Position(4, 4) , Position(1,7)} , 
        {}),

        PieceTestCase("invalid test" , 13 , {Position(4, 4) , Position(6,3)} , 
        {}),

        PieceTestCase("invalid test" , 14 , {Position(4, 4) , Position(7,2)} , 
        {}),

        PieceTestCase("invalid test" , 15 , {Position(4, 4) , Position(7,1)} , 
        {}),

        PieceTestCase("valid test" , 16 , {Position(4, 4) , Position(3,4)} , 
        {Position(3 ,4)}),

        PieceTestCase("valid test" , 17 , {Position(4, 4) , Position(2,4)} , 
        {Position(3 ,4),Position(2 ,4)}),

        PieceTestCase("valid test" , 18 , {Position(4, 4) , Position(1,4)} , 
        {Position(3 ,4),Position(2 ,4),Position(1 ,4)}),

        PieceTestCase("valid test" , 19 , {Position(4, 4) , Position(4,5)} , 
        {Position(4 ,5)}),

        PieceTestCase("valid test" , 20 , {Position(4, 4) , Position(4,6)} , 
        {Position(4 ,5),Position(4,6)}),

        PieceTestCase("valid test" , 21 , {Position(4, 4) , Position(4,7)} , 
        {Position(4 ,5),Position(4,6),Position(4,7)}),

        PieceTestCase("valid test" , 22 , {Position(4, 4) , Position(4,3)} , 
        {Position(4 ,3)}),

        PieceTestCase("valid test" , 23 , {Position(4, 4) , Position(4,2)} , 
        {Position(4 ,3),Position(4,2)}),

        PieceTestCase("valid test" , 24 , {Position(4, 4) , Position(4,1)} , 
        {Position(4 ,3),Position(4,2),Position(4,1)}),

        PieceTestCase("valid test" , 25 , {Position(4, 4) , Position(5,4)} , 
        {Position(5,4)}),

        PieceTestCase("valid test" , 26 , {Position(4, 4) , Position(6,4)} , 
        {Position(5,4),Position(6,4)}),

        PieceTestCase("valid test" , 27 , {Position(4, 4) , Position(7,4)} , 
        {Position(5,4),Position(6,4),Position(7,4)})
    };

    TestRunner <RockPiece> testRunner;
    testRunner.runTests(testCases);


    return 0;

}