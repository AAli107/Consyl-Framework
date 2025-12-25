#!/bin/bash

BUILD_FOLDER="build"
SRC_FOLDER="src"
EXE_OUTPUT_FILE="program.exe"

rm -rf "$BUILD_FOLDER"

mkdir -p "$BUILD_FOLDER"

CPP_FILES=$(find "$SRC_FOLDER" -name "*.cpp")

g++ -std=c++20 -O3 $CPP_FILES -o "$BUILD_FOLDER/$EXE_OUTPUT_FILE"

if [ -f "$BUILD_FOLDER/$EXE_OUTPUT_FILE" ]; then
    "./$BUILD_FOLDER/$EXE_OUTPUT_FILE"
fi
