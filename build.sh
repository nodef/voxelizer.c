#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -f "voxelizer.h" ]; then return; fi
URL="https://github.com/karimnaaji/voxelizer/raw/refs/heads/master/voxelizer.h"
FILE="voxelizer.h"

# Download the release
echo "Downloading $FILE from $URL ..."
curl -L "$URL" -o "$FILE"
echo ""
}


# Test the project
test() {
echo "Running 01-basic-voxelization.c ..."
clang -I. -o 01.exe examples/01-basic-voxelization.c && ./01 && echo -e "\n"
echo "Running 02-voxelize-sphere.c ..."
clang -I. -o 02.exe examples/02-voxelize-sphere.c    && ./02 && echo -e "\n"
echo "Running 03-voxelize-complex.c ..."
clang -I. -o 03.exe examples/03-voxelize-complex.c   && ./03 && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
