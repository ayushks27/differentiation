#pragma once

#include <vector>
#include <memory>
#include "Algorithm.h"

class AlgorithmRegistry {
public:
    static void registerAlgorithm(std::unique_ptr<Algorithm> algo);
    static std::vector<std::unique_ptr<Algorithm>>& getAll();
};
