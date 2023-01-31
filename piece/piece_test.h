#include "../test_class/successfull_test.h"
#include "piece.h"


struct PieceTestCaseInput {
public:
    Position initialPosintion, finalPosition;
};


typedef vector<Position> PieceTestCaseOutput;


typedef SuccessfullTest<PieceTestCaseInput
        , PieceTestCaseOutput> PieceTestCase;






template <typename PieceClass>
class TestRunner {
private:
    bool isSameOutput(PieceTestCaseOutput testCaseOutput
        , PieceTestCaseOutput &testCaseRunOutput) {
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
public:
    void runTests (vector<PieceTestCase> &testCases) {

        for (PieceTestCase &testCase : testCases) {
            PieceClass *piece = new PieceClass(WHIGHT_COLOR, testCase.getTestInput().initialPosintion);
            PieceTestCaseOutput testCaseRunOutput = piece->pathTo(testCase.getTestInput().finalPosition);
            if (isSameOutput(testCase.getTestOutput(), testCaseRunOutput)) {
                cout << "[Test Passed] ";
            } else {
                cout << "[Test Failed] ";
            }

            cout << "Test id (" << testCase.getId() << "), Test Name(" << testCase.getName() << ")." << endl;

            cout << endl;
        }
    }
};

