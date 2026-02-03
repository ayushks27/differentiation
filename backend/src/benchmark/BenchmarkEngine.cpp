#include "BenchmarkEngine.h"
#include "../core/AlgorithmRegistry.h"
#include <chrono>
#include <limits>

std::vector<BenchmarkResult> BenchmarkEngine::runAll(size_t inputSize) {
    std::vector<BenchmarkResult> results;

    for (auto& algo : AlgorithmRegistry::getAll()) {
        double total = 0.0;
        double minTime = std::numeric_limits<double>::max();
        double maxTime = 0.0;

        const int runs = 5; // 🔁 repeat for stability

        for (int i = 0; i < runs; ++i) {
            auto start = std::chrono::high_resolution_clock::now();
            algo->run(inputSize);
            auto end = std::chrono::high_resolution_clock::now();

            double ms = std::chrono::duration<double, std::milli>(end - start).count();

            total += ms;
            minTime = std::min(minTime, ms);
            maxTime = std::max(maxTime, ms);
        }

        results.push_back({
            algo->name(),
            algo->category(),
            inputSize,
            total / runs,
            minTime,
            maxTime
        });
    }

    return results;
}
