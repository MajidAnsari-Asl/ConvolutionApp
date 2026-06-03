#include "ConvolutionProcessor.hpp"

cv::Mat ConvolutionProcessor::apply(
    const cv::Mat& image,
    const cv::Mat& kernel)
{
    cv::Mat imageFloat;
    image.convertTo(imageFloat, CV_32F);

    cv::Mat result;

    cv::filter2D(
        imageFloat,
        result,
        -1,
        kernel,
        cv::Point(-1, -1),
        0.0,
        cv::BORDER_REFLECT101);

    return result;
}