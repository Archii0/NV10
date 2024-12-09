#include "IAccelerator.hpp"
#include "TestSuite.hpp"
class ArchitecturalValidationSuite : public TestSuite {
   public:
    void runTests(IAccelerator& gpu) override;
};