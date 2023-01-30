






#ifndef SUCCESSFULL_TEST_CLASS_DECLARATION
#define SUCCESSFULL_TEST_CLASS_DECLARATION




#include <iostream>
#include "test.h"



using namespace std;



template <typename TestOutput>

class SuccessfullTest {
protected:
    TestOutput testOutput;


public:
    SuccessfullTest(string name, int id, TestInput testInput, TestOutput testOutput);


};






#endif // SUCCESSFULL_TEST_CLASS_DECLARATION