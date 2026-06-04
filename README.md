# ConvolutionApp

A modern C++ image convolution application built with OpenCV.

The program loads an image and a user-defined convolution kernel, applies the kernel using either OpenCV's built-in implementation or a custom convolution algorithm, and saves the resulting image to disk.

This project was developed to demonstrate image processing fundamentals, modern C++ design, and software engineering practices including modular architecture, encapsulation, error handling, and performance measurement.

---

## Features

* Load images using OpenCV
* Load arbitrary convolution kernels from text files
* Support kernels of any size (3×3, 5×5, 7×7, ...)
* Two convolution implementations:

  * OpenCV `filter2D`
  * Custom convolution implementation
* Command-line interface
* Performance benchmarking using `std::chrono`
* Modular architecture
* Modern C++ (C++17)

---

## Project Structure

```text
ConvolutionApp/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── Kernel.hpp
│   ├── KernelLoader.hpp
│   └── Convolution.hpp
│
├── src/
│   ├── main.cpp
│   ├── Kernel.cpp
│   ├── KernelLoader.cpp
│   └── Convolution.cpp
│
├── kernels/
│   ├── sharpen.txt
│   └── blur.txt
│
├── inImages/
└── outResults/
```

---

## Requirements

### macOS

Install dependencies using Homebrew:

```bash
brew install opencv
brew install cmake
```

---

## Build

Create a build directory and compile the project:

```bash
mkdir build
cd build

cmake ..
make
```

The executable will be generated as:

```text
ConvolutionApp
```

---

## Usage

```bash
./ConvolutionApp <image> <kernel> <output> <builtin|custom>
```

### Example

Using custom implementation:

```bash
./ConvolutionApp \
    ../inImages/input.jpg \
    ../kernels/sharpen.txt \
    ../outResults/output.png \
    custom
```

Using OpenCV's implementation:

```bash
./ConvolutionApp \
    ../inImages/input.jpg \
    ../kernels/sharpen.txt \
    ../outResults/output.png \
    builtin
```

---

## Kernel File Format

The kernel file starts with the number of rows and columns followed by the kernel coefficients.

Example:

```text
3 3
0 -1  0
-1 5 -1
0 -1  0
```

Another example:

```text
5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
```

The application supports arbitrary kernel dimensions.

---

## Architecture

### Kernel

Represents a convolution kernel and provides:

* Kernel storage
* Access to coefficients
* Dimension information

Example:

```cpp
kernel.rows();
kernel.cols();
kernel.at(r, c);
```

### KernelLoader

Responsible for reading kernel files and constructing `Kernel` objects.

### Convolution

Provides two implementations:

#### Built-in

Uses OpenCV's optimized implementation:

```cpp
cv::filter2D(...)
```

#### Custom

Performs convolution manually using nested loops.

This implementation is useful for understanding convolution fundamentals and benchmarking against OpenCV.

---

## Performance Measurement

Execution time is measured using `std::chrono`.

Example output:

```text
Convolution took 628 ms
```

This allows comparison between OpenCV's optimized implementation and the custom implementation.

---

## Convolution vs Correlation

Strict mathematical convolution requires flipping the kernel before applying it to the image.

Many image-processing libraries internally perform correlation rather than strict convolution.

The custom implementation can easily be modified to support true convolution by reversing kernel indices during accumulation.

---

## Example Kernels

### Sharpen

```text
3 3
0 -1  0
-1 5 -1
0 -1  0
```

### Edge Detection

```text
3 3
-1 -1 -1
-1  8 -1
-1 -1 -1
```

### Box Blur

```text
3 3
0.111 0.111 0.111
0.111 0.111 0.111
0.111 0.111 0.111
```

---

## Technologies

* C++17
* OpenCV
* CMake
* STL
* std::filesystem
* std::chrono

---

## Learning Objectives

This project demonstrates:

* Image convolution fundamentals
* OpenCV image processing
* Modern C++ design
* Encapsulation and modularity
* Performance measurement
* File parsing
* Command-line applications

---

## License

This project is provided for educational and demonstration purposes.
