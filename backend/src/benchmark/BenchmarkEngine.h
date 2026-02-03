#pragma once

#include <vector>
#include "../core/Algorithm.h"
#include "BenchmarkResult.h"

class BenchmarkEngine {
public:
    static std::vector<BenchmarkResult> runAll(size_t inputSize);
};
