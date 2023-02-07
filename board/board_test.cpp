#include "board_test.h"


BoardUnitTest::BoardUnitTest() {

}



template <typename testCase>
void BoardUnitTest::printTestResult(bool testCaseRunOutput
        , const testCase &testCase) {
    if (testCaseRunOutput == testCase.getTestOutput()) {
        cout << "[Test Passed] ";
    } else {
        cout << "[Test Failed] ";
    }

    cout << "Test id (" << testCase.getId() << "), Test Name(" << testCase.getName() << ")." << endl;

}


void BoardUnitTest::validPositionsFuncTests(Board* board,
        vector <ValidPositionsFuncUnitTestCase> *testCases) {
        
    for (ValidPositionsFuncUnitTestCase &testCase : *testCases) {

        bool testCaseRunOutput = board
                                ->validPositions(
                                    testCase.getTestInput().startPosition, 
                                    testCase.getTestInput().destinationPosition);

        printTestResult(testCaseRunOutput, testCase);
    }
}


void BoardUnitTest::existOpponentPieceAtEndOfPathFuncTest(Board *board
                , vector <existOpponentPieceAtEndOfPathFuncUnitTestCase> *testCases) {
    for (existOpponentPieceAtEndOfPathFuncUnitTestCase &testCase : *testCases) {

        bool testCaseRunOutput = board
                                ->existOpponentPieceAtEndOfPath(
                                    testCase.getTestInput());

        printTestResult(testCaseRunOutput, testCase);
    }
}


void BoardUnitTest::pawnValidPathFuncTest(Board *board,
                vector <PawnValidPathFuncUnitTestCase> *testCases) {
    for (PawnValidPathFuncUnitTestCase &testCase : *testCases) {

        bool testCaseRunOutput = board
                                ->pawnValidPath(
                                    testCase.getTestInput().startPosition,
                                    testCase.getTestInput().pawnPath);

        printTestResult(testCaseRunOutput, testCase);
    }
}




void BoardUnitTest::pathIsBlockedFuncTest(Board *board,
                vector <pathIsBlockedFuncUnitTestCase> *testCases) {
    for (pathIsBlockedFuncUnitTestCase &testCase : *testCases) {

        bool testCaseRunOutput = board
                                ->pathIsBlocked(
                                    testCase.getTestInput());

        printTestResult(testCaseRunOutput, testCase);
    }
}


void BoardUnitTest::validPathFuncTest(Board *board,
                vector <validPathFuncUnitTestCase> *testCases) {
    for (pathIsBlockedFuncUnitTestCase &testCase : *testCases) {

        bool testCaseRunOutput = board
                                ->pathIsBlocked(
                                    testCase.getTestInput());

        printTestResult(testCaseRunOutput, testCase);
    }
}


void BoardUnitTest::kingIsThreatedFuncTest(Board *board,
                vector <kingIsThreatedFuncUnitTestCase> *testCases) {
    for (kingIsThreatedFuncUnitTestCase &testCase : *testCases) {

        bool testCaseRunOutput = board
                                ->kingIsThreated();

        printTestResult(testCaseRunOutput, testCase);
    }
}

void BoardUnitTest::validMoveFuncTest(Board *board,
                vector <validMoveFuncUnitTestCase> *testCases) {
    for (validMoveFuncUnitTestCase &testCase : *testCases) {

        bool testCaseRunOutput = board
                                ->validMove(
                                    testCase.getTestInput().startPosition,
                                    testCase.getTestInput().destinationPosition);

        printTestResult(testCaseRunOutput, testCase);
    }
}

