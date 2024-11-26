#!/bin/bash

set -e

SOURCE_DIR="src"
BUILD_DIR="build"
OUTPUT_FILE="my_program"

mkdir -p $BUILD_DIR

echo "source files are being compiled"
gcc $SOURCE_DIR/*.c -o $BUILD_DIR/$OUTPUT_FILE

echo "affirmative, Output file: $BUILD_DIR/$OUTPUT_FILE"
