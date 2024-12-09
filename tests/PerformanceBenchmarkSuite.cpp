#include "IAccelerator.hpp"
#include "TestSuite.hpp"

class PerformanceBenchmarkSuite : public TestSuite {
   private:
    int workloadSize;

   public:
    PerformanceBenchmarkSuite(int size) : workloadSize(size) {}
    void runTests(IAccelerator& gpu) override;
};