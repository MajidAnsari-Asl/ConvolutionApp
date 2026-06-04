#pragma once

#include <filesystem>
#include <stdexcept>
#include "Kernel.hpp"

class KernelLoader
{
public:
    static Kernel load(const std::filesystem::path& path);
};