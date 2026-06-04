#pragma once

#include <vector>
#include <cstddef>

class Kernel
{
public:
    Kernel() = default;

    Kernel(size_t rows,
           size_t cols,
           std::vector<float> values);

    float at(size_t r,
             size_t c) const;

    size_t rows() const noexcept;
    size_t cols() const noexcept;

    bool empty() const noexcept;

private:
    size_t rows_{0};
    size_t cols_{0};

    std::vector<float> values_;
};