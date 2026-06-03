#pragma once

#include <opencv2/opencv.hpp>
#include <string>

class KernelLoader
{
public:
    static cv::Mat load(const std::string& filename);
};