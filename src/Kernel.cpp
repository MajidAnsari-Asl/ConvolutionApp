#include "Kernel.hpp"

Kernel::Kernel(size_t rows,
               size_t cols,
               std::vector<float> values)
    : rows_(rows),
      cols_(cols),
      values_(std::move(values))
{
}

float Kernel::at(size_t r,
                 size_t c) const
{
    return values_[r * cols_ + c];
}

size_t Kernel::rows() const noexcept
{
    return rows_;
}

size_t Kernel::cols() const noexcept
{
    return cols_;
}

bool Kernel::empty() const noexcept
{
    return values_.empty();
}