
#include "../piece_test.h"
#include "bishop.h"


int main() {

    vector <PieceTestCase> testCases = {
        PieceTestCase("valid test" , 1 , {Position(4, 4) , Position(5,5)} , 
        {Position(5 ,5)}),

        PieceTestCase("valid test" , 2 , {Position(4, 4) , Position(6,6)} , 
        {Position(5 ,5) , Position(6,6)}),

        PieceTestCase("valid test" , 3 , {Position(4, 4) , Position(7,7)} , 
        {Position(5 ,5) , Position(6,6) , Position(7,7)}),

        PieceTestCase("valid test" , 4 , {Position(4, 4) , Position(5,3)} , 
        {Position(5 ,3)}),

        PieceTestCase("valid test" , 5 , {Position(4, 4) , Position(6,2)} , 
        {Position(5 ,3) , Position(6 , 2)}),

        PieceTestCase("valid test" , 6 , {Position(4, 4) , Position(7,1)} , 
        {Position(5 ,3) , Position(6 , 2) , Position(7 , 1)}),

        PieceTestCase("valid test" , 7 , {Position(4, 4) , Position(3,3)} , 
        {Position(3 ,3)}),

        PieceTestCase("valid test" , 8 , {Position(4, 4) , Position(2,2)} , 
        {Position(3 ,3) , Position(2 , 2)}),

        PieceTestCase("valid test" , 9 , {Position(4, 4) , Position(1,1)} , 
        {Position(3 ,3) , Position(2 , 2) , Position(1, 1)}),

        PieceTestCase("valid test" , 10 , {Position(4, 4) , Position(3,5)} , 
        {Position(3 ,5)}),

        PieceTestCase("valid test" , 11 , {Position(4, 4) , Position(2,6)} , 
        {Position(3 ,5) , Position(2 , 6)}),

        PieceTestCase("valid test" , 12 , {Position(4, 4) , Position(1,7)} , 
        {Position(3 ,5) , Position(2 , 6) , Position(1 , 7)}),

        PieceTestCase("invalid test" , 13 , {Position(4, 4) , Position(6,3)} , 
        {}),

        PieceTestCase("invalid test" , 14 , {Position(4, 4) , Position(7,2)} , 
        {}),

        PieceTestCase("invalid test" , 15 , {Position(4, 4) , Position(4,3)} , 
        {}),

        PieceTestCase("invalid test" , 16 , {Position(4, 4) , Position(1,4)} , 
        {}),

        PieceTestCase("invalid test" , 17 , {Position(4, 4) , Position(4,7)} , 
        {})        
    };

    TestRunner <BishopPiece> testRunner;
    testRunner.runTests(testCases);


    return 0;

}