#include "IAccelerator.hpp"
#include "TestSuite.hpp"
class FunctionalTestSuite : public TestSuite {
   public:
    void runTests(IAccelerator& gpu) override;
};