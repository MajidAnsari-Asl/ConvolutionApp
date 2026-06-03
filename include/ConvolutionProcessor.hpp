#pragma once

#include <opencv2/opencv.hpp>

class ConvolutionProcessor
{
public:
    static cv::Mat apply(
        const cv::Mat& image,
        const cv::Mat& kernel);
};