






#ifndef FAILING_TEST_CLASS_DECLARATION
#define FAILING_TEST_CLASS_DECLARATION




#include <iostream>
#include "test.h"



using namespace std;


template <typename TestInput>

class FallingTest : public Test <TestInput>{
public:
    FallingTest(string name, int id, TestInput testInput) : Test<TestInput>(name, id, testInput) {
        
    }

};






#endif // FAILING_TEST_CLASS_DECLARATION