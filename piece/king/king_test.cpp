
#include "../piece_test.h"
#include "king_piece.h"


int main() {

    vector <PieceTestCase> testCases = {
        PieceTestCase("Conrner test", 1, {Position(0, 0), Position(1, 1)}, {Position(1, 1)}),
        PieceTestCase("Conrner test", 2, {Position(7, 7), Position(6, 6)}, {Position(6, 6)}),
        PieceTestCase("Center Test", 3, {Position(4, 4), Position(4, 3)}, {Position(4, 3)}),
        PieceTestCase("Edg Test", 4, {Position(0, 4), Position(0, 3)}, {Position(0, 3)}),
        PieceTestCase("Invalid Move Test", 5, {Position(5, 6), Position(5, 6)}, {}),
        PieceTestCase("Edg Test", 6, {Position(4, 0), Position(3, 0)}, {Position(3, 0)}),
    };

    TestRunner <KingPiece> testRunner;
    testRunner.runTests(testCases);


    return 0;

}