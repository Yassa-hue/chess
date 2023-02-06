
#include "../piece_test.h"
#include "knight.h"


int main() {

    vector <PieceTestCase> testCases = {
        PieceTestCase("valid test", 1, {Position(4, 4), Position(6, 3)}, {Position(6, 3)}),
        PieceTestCase("valid test", 2, {Position(4, 4), Position(6, 5)}, {Position(6, 5)}),
        PieceTestCase("valid test", 3, {Position(4, 4), Position(5, 2)}, {Position(5, 2)}),
        PieceTestCase("valid test", 4, {Position(4, 4), Position(5, 6)}, {Position(5, 6)}),
        PieceTestCase("valid test", 5, {Position(4, 4), Position(3, 6)}, {Position(3, 6)}),
        PieceTestCase("valid test", 6, {Position(4, 4), Position(2, 5)}, {Position(2, 5)}),
        PieceTestCase("valid test", 7, {Position(4, 4), Position(2, 3)}, {Position(2, 3)}),
        PieceTestCase("valid test", 8, {Position(4, 4), Position(3, 2)}, {Position(3, 2)}),
        PieceTestCase("invalid test", 9, {Position(4, 4), Position(4, 5)}, {}),
        PieceTestCase("invalid test", 10, {Position(4, 4), Position(4, 6)}, {}),
        PieceTestCase("invalid test", 11, {Position(4, 4), Position(5, 5)}, {}),
        PieceTestCase("invalid test", 12, {Position(4, 4), Position(5, 4)}, {}),
        PieceTestCase("invalid test", 13, {Position(4, 4), Position(6, 2)}, {}),
        PieceTestCase("invalid test", 14, {Position(4, 4), Position(4, 2)}, {})
    };

    TestRunner <KnightPiece> testRunner;
    testRunner.runTests(testCases);


    return 0;

}