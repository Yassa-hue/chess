
#include "../piece_test.h"
#include "pawn.h"


int main() {

    vector <PieceTestCase> testCases = {
        PieceTestCase("valid test white", 1, {Position(4, 4), Position(3, 4)}, {Position(3, 4)}),
        PieceTestCase("valid test white", 2, {Position(4, 4), Position(3, 5)}, {Position(3, 5)}),
        PieceTestCase("valid test white", 3, {Position(4, 4), Position(3, 3)}, {Position(3, 3)}),
        PieceTestCase("valid test white special move", 4, {Position(6, 4), Position(4, 4)}, {Position(5 , 4) , Position(4, 4)}),
        PieceTestCase("invalid move", 5, {Position(4, 4), Position(2, 4)}, {})
    };

    TestRunner <PawnPiece> testRunner;
    testRunner.runTests(testCases , WHIGHT_COLOR);
    testCases.clear();
    testCases = {
        PieceTestCase("valid test black", 6, {Position(4, 4), Position(5, 4)}, {Position(5, 4)}),
        PieceTestCase("valid test black", 7, {Position(4, 4), Position(5, 5)}, {Position(5, 5)}),
        PieceTestCase("valid test black", 8, {Position(4, 4), Position(5, 3)}, {Position(5, 3)}),
        PieceTestCase("valid test black special move", 9, {Position(1, 4), Position(3, 4)}, {Position(2 , 4) , Position(3, 4)}),
        PieceTestCase("invalid move", 10, {Position(4, 4), Position(2, 4)}, {})
    };

    testRunner.runTests(testCases , BLACK_COLOR);

    return 0;

}