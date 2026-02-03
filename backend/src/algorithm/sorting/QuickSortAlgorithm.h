#pragma once
#include "../../core/Algorithm.h"

class QuickSortAlgorithm : public Algorithm {
public:
    std::string name() const override;
    std::string category() const override;
    void run(std::size_t inputSize) override;
};
