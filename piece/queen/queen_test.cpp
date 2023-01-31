#include "../piece_test.h"
#include "queen.h"


int main () {
    // 4, 3 => 4, 5
    PiecePath testCase1Output = {
        Position(4, 4),
        Position(4, 5),
    };


    // 1, 6 => 0, 7
    PiecePath testCase2Output = {
        Position(0, 7),
    };


    // 7, 0 => 5, 0
    PiecePath testCase3Output = {
        Position(6, 0),
        Position(5, 0),
    };


    // 4, 4 => 0, 0
    PiecePath testCase4Output = {
        Position(3, 3),
        Position(2, 2),
        Position(1, 1),
        Position(0, 0)
    };

    // 7, 7 => 7, 5
    PiecePath testCase5Output = {
        Position(7, 6),
        Position(7, 5),
    };

    // 0, 7 => 7, 0
    PiecePath testCase6Output = {
        Position(1, 6),
        Position(2, 5),
        Position(3, 4),
        Position(4, 3),
        Position(5, 2),
        Position(6, 1),
        Position(7, 0)
    };

    // 3, 4 => 5, 4
    PiecePath testCase7Output = {
        Position(4, 4),
        Position(5, 4),
    };


    // 5, 5 => 6, 6
    PiecePath testCase8Output = {
        Position(6, 6),
    };


    // 6, 6 => 6, 6
    PiecePath testCase9Output = {

    };


    
    vector <PieceTestCase> testCases = {
        PieceTestCase(
            "Right test", 
            1, 
            {
                Position(4, 3),
                Position(4, 5)
            }, 
            testCase1Output
        ),
        PieceTestCase(
            "Upper right test", 
            2, 
            {
                Position(1, 6), 
                Position(0, 7)
            }, 
            testCase2Output
        ),
        PieceTestCase(
            "Up Test", 
            3, 
            {
                Position(7, 0), 
                Position(5, 0)
            }, 
            testCase3Output
        ),
        PieceTestCase(
            "Upper left", 
            4, 
            {
                Position(4, 4), 
                Position(0, 0)
            }, 
            testCase4Output
        ),
        PieceTestCase(
            "Left Test", 
            5, 
            {
                Position(7, 7), 
                Position(7, 5)
            }, 
            testCase5Output
        ),
        PieceTestCase(
            "Left down Test", 
            6, 
            {
                Position(0, 7), 
                Position(7, 0)
            }, 
            testCase6Output
        ),
        PieceTestCase(
            "Down Test", 
            7, 
            {
                Position(3, 4), 
                Position(5, 4)
            }, 
            testCase7Output
        ),
        PieceTestCase(
            "Down right Test", 
            8, 
            {
                Position(5, 5), 
                Position(6, 6)
            }, 
            testCase8Output
        ),
        PieceTestCase(
            "Invalid move Test", 
            9, 
            {
                Position(6, 6), 
                Position(6, 6)
            }, 
            testCase9Output
        ),
    };

    TestRunner <QueenPiece> testRunner;
    testRunner.runTests(testCases);
}