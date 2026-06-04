#include "KernelLoader.hpp"

#include <fstream>
#include <stdexcept>

Kernel KernelLoader::load(
    const std::filesystem::path& path)
{
    std::ifstream file(path);

    if (!file)
    {
        throw std::runtime_error(
            "Cannot open kernel file");
    }

    size_t rows;
    size_t cols;

    file >> rows >> cols;

    std::vector<float> values;
    values.reserve(rows * cols);

    float v;

    while (file >> v)
    {
        values.push_back(v);
    }

    if (values.size() != rows * cols)
    {
        throw std::runtime_error(
            "Kernel size mismatch");
    }

    return Kernel(rows,
                  cols,
                  std::move(values));
}