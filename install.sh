#!/bin/bash

# Define variables
VCPKG_REPO="https://github.com/microsoft/vcpkg.git"
VCPKG_DIR="$HOME/vcpkg"
REPO_URL="git@github.com:onvasrouler/R-type.git"
REPO_DIR="r-types"
BRANCH="r-type-installer"
PLATFORM=$(uname)

rm -rf build

command_exists() {
    command -v "$1" >/dev/null 2>&1
}

echo "Installing system dependencies..."
if command_exists apt; then
    sudo apt update
    sudo apt install -y git cmake build-essential curl unzip uuid-dev clang-format
elif command_exists dnf; then
    sudo dnf install -y git cmake gcc-c++ curl unzip libuuid-devel clang-tools-extra
elif command_exists brew; then
    brew install git cmake curl unzip clang-format
else
    echo "Error: Unsupported package manager. Please install git, cmake, curl, and unzip manually."
    exit 1
fi

if [ ! -d "$VCPKG_DIR" ]; then
    echo "Cloning vcpkg..."
    git clone $VCPKG_REPO $VCPKG_DIR
    cd $VCPKG_DIR
    ./bootstrap-vcpkg.sh
else
    echo "vcpkg already installed at $VCPKG_DIR"
fi


echo "Installing required packages..."
if [[ "$PLATFORM" == "Darwin" ]]; then
    echo "Detected macOS, skipping uuid installation."
    $VCPKG_DIR/vcpkg install boost gtest sfml
else
    echo "Detected $PLATFORM, installing Boost, gtest, and uuid."
    $VCPKG_DIR/vcpkg install boost gtest sfml
fi

if [ ! -d "$REPO_DIR" ]; then
    echo "Cloning project repository..."
    git clone $REPO_URL $REPO_DIR
    cd $REPO_DIR
    git checkout $BRANCH
else
    echo "Project repository already exists at $REPO_DIR"
    cd $REPO_DIR
fi

rm -rf build

make
