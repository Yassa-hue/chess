#include "king_piece.h"
#include "../../test_class/successfull_test.h"


struct KingPieceTestCaseInput {
public:
    Position initialPosintion, finalPosition;
};


typedef vector<Position> KingPieceTestCaseOutput;


typedef SuccessfullTest<KingPieceTestCaseInput
        , KingPieceTestCaseOutput> KingPieceTestCase;

bool isSameOutput(KingPieceTestCaseOutput testCaseOutput
    , KingPieceTestCaseOutput &testCaseRunOutput) {
    if (testCaseOutput.size() != testCaseRunOutput.size()) {
        return false;
    }

    for (int i = 0; i < testCaseRunOutput.size(); i++) {
        if (testCaseOutput[i] != testCaseRunOutput[i]) {
            return false;
        }
    }

    return true;
}

void runTests (vector<KingPieceTestCase> &testCases) {

    for (KingPieceTestCase &testCase : testCases) {
        KingPiece *kingPiece = new KingPiece(WHIGHT_COLOR, testCase.getTestInput().initialPosintion);
        KingPieceTestCaseOutput testCaseRunOutput = kingPiece->pathTo(testCase.getTestInput().finalPosition);
        // cout << "Test id (" << testCase.getId() << "), Test Name(" << testCase.getName() << ")." << endl;
        if (isSameOutput(testCase.getTestOutput(), testCaseRunOutput)) {
            cout << "[Test Passed] ";
        } else {
            cout << "[Test Failed] ";
        }

        cout << "Test id (" << testCase.getId() << "), Test Name(" << testCase.getName() << ")." << endl;

        cout << endl;
    }
}


 

