#!/bin/bash

# Set the source, include, and build directories
SRC_DIR="./src"
INCLUDE_DIR="./include"
BUILD_DIR="./build"
EXECUTABLE="connect4"

# Create the build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Compile the game with g++ and SFML libraries
g++ -std=c++17 $SRC_DIR/*.cpp -I$INCLUDE_DIR -o $BUILD_DIR/$EXECUTABLE \
  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Check if the compilation was successful
if [ $? -eq 0 ]; then
  echo "Compilation successful!"
  echo "You can run the game using: $BUILD_DIR/$EXECUTABLE"
else
  echo "Compilation failed."
fi
