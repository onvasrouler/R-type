#!/bin/bash


# Clean up previous builds
[ -d build ] && rm -rf build
[ -d Result ] && rm -rf Result

# Detect operating system
OS=$(uname)
if [ "$OS" == "Linux" ]; then
    echo "Running on Linux"
else
    echo "Running on Windows"
fi

cmake --build . --target clean

if [ "$1" == "clean" ]; then
    exit 0
elif [ "$1" == "client" ]; then
    echo "Building client"
    cmake -S . -B build -DTESTS=OFF -DSERVER=OFF -DCLIENT=ON -Wno-dev
    if [ $? -ne 0 ]; then
        echo "CMake configuration failed!"
        exit 1
    fi
    cd build
    cmake --build .
    if [ $? -ne 0 ]; then
        echo "Build failed! See build_log.txt for details."
        exit 1
    fi
    cd ..
    mkdir -p Result/client
    cp -r build/client/RType Result/client/
    cp -r client/config Result/client/config/
    cp -r client/assets Result/client/assets/

    echo "Client built!"
else
    echo "No argument given !"
fi