#!/bin/sh

COMPILER=""
DEBUG=0
ASAN=0
UBSAN=0

while getopts "c:daus" opt; do
    case $opt in
        c)
            COMPILER=$OPTARG
            ;;
        d)
            DEBUG=1
            ;;
        a)
            ASAN=1
            ;;
        u)
            UBSAN=1
            ;;
        s)
            ASAN=1
            UBSAN=1
            ;;
        \?)
            echo "Usage: $0 [-c 'Compiler'] [-d 'Debug'] [-a 'AddressSan] [-u 'UBSan'] [-s 'San']"
            exit 1
            ;;
    esac
done

# Compiler
if [ -z "$COMPILER" ]; then
    echo "Usage: $0 [-c 'Compiler'] [-d 'Debug'] [-a 'AddressSan] [-u 'UBSan'] [-s 'San']"
    exit 1
fi

if [ "$COMPILER" = "gcc" ]; then
    CMAKE_FLAGS="-DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++"
elif [ "$COMPILER" = "clang" ]; then
    CMAKE_FLAGS="-DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++"
else
    echo "Error: Unsupported compiler. Use 'gcc' or 'clang'"
    exit 1
fi 

mkdir -p build
cd build

# Debug
if [ $DEBUG -eq 1 ]; then
    CMAKE_FLAGS="$CMAKE_FLAGS -DCMAKE_BUILD_TYPE=Debug"
else
    CMAKE_FLAGS="$CMAKE_FLAGS -DCMAKE_BUILD_TYPE=Release"
fi

# Sanitizers
SANITIZERS_FLAG=""

if [ $ASAN -eq 1 ]; then
    SANITIZERS_FLAG="$SANITIZERS_FLAG -fsanitize=address"
fi

if [ $UBSAN -eq 1 ]; then
    SANITIZERS_FLAG="$SANITIZERS_FLAG -fsanitize=undefined"
fi

if [ -n "SANITIZERS_FLAG" ]; then
    CMAKE_FLAGS="$CMAKE_FLAGS -DCMAKE_CXX_FLAGS='$SANITIZER_FLAGS'"
    CMAKE_FLAGS="$CMAKE_FLAGS -DCMAKE_EXE_LINKER_FLAGS='$SANITIZER_FLAGS'"
fi

cmake $CMAKE_FLAGS ..
make
