#!/bin/bash -x

# Clean build folder
rm -rf build

# Build & Run unit tests & create conan package
conan profile detect --force

# Install conan package
conan install . --output-folder=build --build=missing

# Generate build system
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build . --config Release

# Run test scripts
ctest .

# Print help message
./main/Start -h 

# Create a start
./main/Start --create --width 10

# Return back from build folder to project folder
cd ..
