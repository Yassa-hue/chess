#include "board.h"
#include "../test_class/successfull_test.h"


struct ValidPositionsFuncUnitTestInput {
public:
    Position startPosition, destinationPosition;
};
typedef SuccessfullTest<ValidPositionsFuncUnitTestInput, bool> ValidPositionsFuncUnitTestCase;




typedef SuccessfullTest<Position, bool> existOpponentPieceAtEndOfPathFuncUnitTestCase;




struct PawnValidPathFuncUnitTestInput {
public:
    Position startPosition;
    PiecePath pawnPath;
};
typedef SuccessfullTest<PawnValidPathFuncUnitTestInput, bool> PawnValidPathFuncUnitTestCase;




typedef SuccessfullTest<PiecePath, bool> pathIsBlockedFuncUnitTestCase;



typedef SuccessfullTest<PiecePath, bool> validPathFuncUnitTestCase;



typedef SuccessfullTest<void, bool> kingIsThreatedFuncUnitTestCase;



struct validMoveFuncUnitTestInput {
public:
    Position startPosition, destinationPosition;
};
typedef SuccessfullTest<validMoveFuncUnitTestInput, bool> validMoveFuncUnitTestCase;



class BoardUnitTest {
protected:
    template <typename TestCase>
    void printTestResult(bool testCaseRunOutput, const TestCase &testCase);

public:
    BoardUnitTest();

    void validPositionsFuncTests(Board *Board
                , vector <ValidPositionsFuncUnitTestCase> *testCases);

    
    void existOpponentPieceAtEndOfPathFuncTest(Board *board,
                vector <existOpponentPieceAtEndOfPathFuncUnitTestCase> *testCases);


    void pawnValidPathFuncTest(Board *board,
                vector <PawnValidPathFuncUnitTestCase> *testCases);

    
    void pathIsBlockedFuncTest(Board *board,
                vector <pathIsBlockedFuncUnitTestCase> *testCases);

    
    void validPathFuncTest(Board *board,
                vector <validPathFuncUnitTestCase> *testCases);


    void kingIsThreatedFuncTest(Board *board,
                vector <kingIsThreatedFuncUnitTestCase> *testCases);


    void validMoveFuncTest(Board *board,
                vector <validMoveFuncUnitTestCase> *testCases);
    
    
    
};




