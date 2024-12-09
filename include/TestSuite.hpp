// include/TestSuite.h
#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "IAccelerator.hpp"
class TestSuite {
   public:
    virtual void runTests(IAccelerator& gpu) = 0;
    virtual ~TestSuite() = default;
};

#endif  // TESTSUITE_H