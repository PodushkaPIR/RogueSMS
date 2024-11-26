#!/bin/sh

COMPILER=$1

mkdir -p build
cd build

if [ -z "$COMPILER" ]; then
    echo "Usage: $0 (gcc|clang)"
    exit 1
fi

if [ "$COMPILER" = "gcc" ]; then
    cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
elif [ "$COMPILER" = "clang" ]; then
    cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
else
    echo "Error: Unsupported compiler. Use 'gcc' or 'clang'"
    exit 1
fi 

make
