#include "FrameworkManager.hpp"

#include "IAccelerator.hpp"

class FrameworkManager {
   private:
    std::unique_ptr<IAccelerator> accelerator;

   public:
    FrameworkManager(std::unique_ptr<IAccelerator> gpuImpl) {}

    void runTests();
    void runValidation();
    void runBenchmarks();
}