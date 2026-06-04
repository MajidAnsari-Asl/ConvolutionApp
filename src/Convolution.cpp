#include "Convolution.hpp"

cv::Mat Convolution::filter2DVersion(
    const cv::Mat& image,
    const Kernel& kernel)
{
    cv::Mat k(
        kernel.rows(),
        kernel.cols(),
        CV_32F);

    cv::Mat imageFloat;
    image.convertTo(imageFloat, CV_32F);

    for (int r = 0; r < k.rows; ++r)
    {
        for (int c = 0; c < k.cols; ++c)
        {
            k.at<float>(r,c) =
                kernel.at(r,c);
        }
    }

    cv::Mat output;

    cv::filter2D(
        imageFloat,
        output,
        -1,
        k,
        cv::Point(-1, -1),
        0.0,
        cv::BORDER_REFLECT101);

    cv::Mat output_t;

    output.convertTo(output_t, image.type());

    return output_t;
}

cv::Mat Convolution::customVersion(
    const cv::Mat& image,
    const Kernel& kernel)
{
    cv::Mat imageFloat;
    image.convertTo(imageFloat, CV_32F);

    std::vector<cv::Mat> channels;
    cv::split(imageFloat, channels);

    std::vector<cv::Mat> channelsOutput;
    channelsOutput.reserve(channels.size());

    const int kRows =
        static_cast<int>(kernel.rows());

    const int kCols =
        static_cast<int>(kernel.cols());

    const int padY = kRows / 2;
    const int padX = kCols / 2;

    for (const auto& ch : channels)
    {
        cv::Mat result =
            cv::Mat::zeros(
                ch.size(),
                CV_32F);

        for (int y = padY;
            y < imageFloat.rows - padY;
            ++y)
        {
            for (int x = padX;
                x < imageFloat.cols - padX;
                ++x)
            {
                float sum = 0.f;

                for (int ky = 0;
                    ky < kRows;
                    ++ky)
                {
                    for (int kx = 0;
                        kx < kCols;
                        ++kx)
                    {
                        int iy =
                            y + ky - padY;

                        int ix =
                            x + kx - padX;

                        float pixel =
                            ch.at<float>(
                                iy,
                                ix);

                        sum += pixel *
                            kernel.at(
                                ky,
                                kx);
                    }
                }

                result.at<float>(y,x)
                    = sum;
            }
        }
        channelsOutput.push_back(result);
    }
    
    cv::Mat mergedResult;
    cv::merge(channelsOutput, mergedResult);

    cv::Mat output;
    mergedResult.convertTo(
        output,
        image.type());

    return output;
}