#include <iostream>
#include <stdexcept>

#include <opencv2/opencv.hpp>

#include "KernelLoader.hpp"
#include "Convolution.hpp"

#include <chrono>

ConvolutionMethod parseMethod(
    const std::string& str)
{
    if (str == "builtin")
    {
        return ConvolutionMethod::Builtin;
    }

    if (str == "custom")
    {
        return ConvolutionMethod::Custom;
    }

    throw std::runtime_error(
        "Unknown convolution method: " + str);
}

int main(
    int argc,
    char* argv[])
{
    if (argc != 5)
    {
        std::cerr
            << "Usage:\n"
            << "./ConvolutionApp image kernel output method\n";

        return EXIT_FAILURE;
    }

    try
    {
        const auto imagePath = argv[1];
        const auto kernelPath = argv[2];
        const auto outputPath = argv[3];
        const auto method = parseMethod(argv[4]);

        cv::Mat image =
            cv::imread(
                imagePath,
                cv::IMREAD_UNCHANGED);

        if (image.empty())
        {
            throw std::runtime_error(
                "Cannot load image");
        }

        auto kernel =
            KernelLoader::load(
                kernelPath);

        cv::Mat result;

        auto start =
            std::chrono::steady_clock::now();

        switch(method)
        {
        case ConvolutionMethod::Builtin:
            result =
                Convolution::filter2DVersion(
                    image,
                    kernel);
            break;

        case ConvolutionMethod::Custom:
            result =
                Convolution::customVersion(
                    image,
                    kernel);
            break;
        }
        auto end =
            std::chrono::steady_clock::now();

        std::cout
            << "Convolution took "
            << std::chrono::duration_cast
            <std::chrono::milliseconds>
            (end - start).count()
            << " ms\n";

            if (!cv::imwrite(outputPath, result))
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
    catch (
        const std::exception& e)
    {
        std::cerr
            << e.what()
            << '\n';

        return EXIT_FAILURE;
    }
}