#include "ConvolutionProcessor.hpp"
#include "KernelLoader.hpp"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 4)
        {
            std::cerr
                << "Usage:\n"
                << "./ConvolutionApp ../inImages/AGon-Spaces - 4.png ../kernels/gaussian.txt ../outResults/output.png\n";

            return EXIT_FAILURE;
        }

        const std::string imagePath = argv[1];
        const std::string kernelPath = argv[2];
        const std::string outputPath = argv[3];

        cv::Mat image = cv::imread(
            imagePath,
            cv::IMREAD_UNCHANGED);

        if (image.empty())
        {
            throw std::runtime_error(
                "Failed to load image.");
        }

        cv::Mat kernel =
            KernelLoader::load(kernelPath);

        cv::Mat result =
            ConvolutionProcessor::apply(
                image,
                kernel);

        cv::Mat output;

        result.convertTo(output, image.type());

        if (!cv::imwrite(outputPath, output))
        {
            throw std::runtime_error(
                "Failed to write image.");
        }

        std::cout
            << "Saved result to: "
            << outputPath
            << std::endl;

        return EXIT_SUCCESS;
    }
    catch (const std::exception& ex)
    {
        std::cerr
            << "Error: "
            << ex.what()
            << std::endl;

        return EXIT_FAILURE;
    }
}