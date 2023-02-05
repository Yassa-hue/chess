#include "board_test_cases.h"


int main () {

    BoardUnitTest *boardUnitTest = new BoardUnitTest();

    Board *board = new Board();

    boardUnitTest->validPositionsFuncTests(board, validPositionsTestCases);

    boardUnitTest->existOpponentPieceAtEndOfPathFuncTest(board, existOpponentPieceAtEndOfPathFuncTestCases);

    boardUnitTest->pawnValidPathFuncTest(board, pawnValidPathFunTestCases);

    boardUnitTest->pathIsBlockedFuncTest(board, pathIsBlockedFunTestCases);

    boardUnitTest->validPathFuncTest(board, validPathFuncTestCases);

    boardUnitTest->kingIsThreatedFuncTest(board, kingIsThreatedFuncTestCases);

    boardUnitTest->kingDieIfPieceMovedFuncTest(board, kingDieIfPieceMovedFunTestCases);

    boardUnitTest->validMoveFuncTest(board, validMoveFuncTestCases);

    return 0;
}