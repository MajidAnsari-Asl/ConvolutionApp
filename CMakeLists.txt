cmake_minimum_required(VERSION 3.16)
project(ConvolutionApp VERSION 1.0 LANGUAGES CXX)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenCV package
find_package(OpenCV REQUIRED)

#include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# add the executable target
add_executable(ConvolutionApp
  src/main.cpp
  src/ConvolutionProcessor.cpp
  src/KernelLoader.cpp
)

# Link OpenCV libraries
target_link_libraries(ConvolutionApp PRIVATE ${OpenCV_LIBS})

# Include the header files
target_include_directories(ConvolutionApp PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
