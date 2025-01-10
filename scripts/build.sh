#!/bin/sh

# Go up one directory and into the 'build' directory
if [ ! -d "../build" ]; then
  echo "Error: Directory '../build' does not exist."
  exit 1
fi
cd ../build || exit 1
pwd

# Clean up the build directory (optional but recommended for a clean build)
rm -rf *

# Release build
echo "Starting release build..."
cmake -DCMAKE_BUILD_TYPE=Release -G "Ninja" ..
if [ $? -ne 0 ]; then
  echo "Error: CMake configuration for release build failed."
  exit 1
fi
ninja
if [ $? -ne 0 ]; then
  echo "Error: Ninja build for release failed."
  exit 1
fi
mv mcclone mcclone-release

# Debug build
echo "Starting debug build..."
cmake -DCMAKE_BUILD_TYPE=Debug -G "Ninja" ..
if [ $? -ne 0 ]; then
  echo "Error: CMake configuration for debug build failed."
  exit 1
fi
ninja
if [ $? -ne 0 ]; then
  echo "Error: Ninja build for debug failed."
  exit 1
fi
# Uncomment the line below if you want to move the debug build binary
# mv mcclone mcclone-debug

# Make mcclone executable
chmod +x mcclone

# Run the program
./mcclone

# List files in the build directory
ls
