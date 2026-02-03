#include "AlgorithmRegistry.h"

static std::vector<std::unique_ptr<Algorithm>> algorithms;

void AlgorithmRegistry::registerAlgorithm(std::unique_ptr<Algorithm> algo) {
    algorithms.push_back(std::move(algo));
}

std::vector<std::unique_ptr<Algorithm>>& AlgorithmRegistry::getAll() {
    return algorithms;
}
