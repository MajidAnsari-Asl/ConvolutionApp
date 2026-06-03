#include "KernelLoader.hpp"

#include <fstream>
#include <stdexcept>

cv::Mat KernelLoader::load(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open kernel file.");
    }

    int rows{};
    int cols{};

    file >> rows >> cols;

    cv::Mat kernel(rows, cols, CV_32F);

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            file >> kernel.at<float>(r, c);
        }
    }

    return kernel;
}