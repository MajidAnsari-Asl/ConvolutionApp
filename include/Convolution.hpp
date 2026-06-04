#pragma once

#include <opencv2/opencv.hpp>

#include "Kernel.hpp"

enum class ConvolutionMethod
{
    Builtin,
    Custom
};

namespace Convolution
{
    cv::Mat filter2DVersion(
        const cv::Mat& image,
        const Kernel& kernel);

    cv::Mat customVersion(
        const cv::Mat& image,
        const Kernel& kernel);
}