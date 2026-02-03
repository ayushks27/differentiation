#include "QuickSortAlgorithm.h"
#include "../../core/AlgorithmRegistry.h"
#include <vector>
#include <algorithm>
#include <random>
#include <memory>

std::string QuickSortAlgorithm::name() const {
    return "Quick Sort";
}

std::string QuickSortAlgorithm::category() const {
    return "Sorting";
}

void QuickSortAlgorithm::run(std::size_t inputSize) {
    std::vector<int> data(inputSize);
    std::mt19937 rng(42);
    std::uniform_int_distribution<> dist(0, 100000);

    for (auto& x : data) x = dist(rng);
    std::sort(data.begin(), data.end());
}

static bool registered = []() {
    AlgorithmRegistry::registerAlgorithm(
        std::make_unique<QuickSortAlgorithm>()
    );
    return true;
}();

