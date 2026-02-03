#pragma once
#include <string>

struct BenchmarkResult {
    std::string name;
    std::string category;
    size_t inputSize;

    double avgMs;
    double minMs;
    double maxMs;
};
