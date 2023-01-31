#include "king_test.h"


int main() {

    vector <KingPieceTestCase> testCases = {
        KingPieceTestCase("Conrner test", 1, {Position(0, 0), Position(1, 1)}, {Position(1, 1)}),
        KingPieceTestCase("Conrner test", 2, {Position(7, 7), Position(6, 6)}, {Position(6, 6)}),
        KingPieceTestCase("Center Test", 3, {Position(4, 4), Position(4, 3)}, {Position(4, 3)}),
        KingPieceTestCase("Edg Test", 4, {Position(0, 4), Position(0, 3)}, {Position(0, 3)}),
        KingPieceTestCase("Invalid Move Test", 5, {Position(5, 6), Position(5, 6)}, {}),
        KingPieceTestCase("Edg Test", 6, {Position(4, 0), Position(3, 0)}, {Position(3, 0)}),
    };


    runTests(testCases);


    return 0;

}