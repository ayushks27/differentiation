#pragma once
#include <string>
#include <cstddef>

class Algorithm {
public:
    virtual ~Algorithm() = default;

    virtual std::string name() const = 0;
    virtual std::string category() const = 0;
    virtual void run(std::size_t inputSize) = 0;
};
