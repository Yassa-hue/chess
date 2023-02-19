



#ifndef TEST_CLASS_DECLARATION
#define TEST_CLASS_DECLARATION




#include <iostream>



using namespace std;



template <typename TestInput>

class Test {
protected:

    string name;
    int id;

    TestInput testInput;


public:

    Test(string name, int id, TestInput testInput) : name(name), id(id), testInput(testInput) {

    }


    const string &getName () const {
        return name;
    }

    int getId () const {
        return id;
    }


    TestInput getTestInput () const {
        return testInput;
    }


};






#endif // TEST_CLASS_DECLARATION