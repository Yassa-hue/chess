






#ifndef SUCCESSFULL_TEST_CLASS_DECLARATION
#define SUCCESSFULL_TEST_CLASS_DECLARATION




#include <iostream>
#include "test.h"



using namespace std;


template <typename TestInput, typename TestOutput>

class SuccessfullTest : public Test<TestInput> {
protected:
    TestOutput testOutput;


public:
    SuccessfullTest(string name, int id, TestInput testInput, TestOutput testOutput) 
        : Test<TestInput>(name, id, testInput), testOutput(testOutput) {

    }


    const TestOutput &getTestOutput () const {
        return testOutput;
    }


};






#endif // SUCCESSFULL_TEST_CLASS_DECLARATION