#!/bin/bash

# Function to check the operating system
os_type=$(uname)

current_dir=$(pwd)

# Check if raylib is already installed
if command -v raylib &> /dev/null
then
    echo "raylib is already installed."
    exit 0
fi

if [[ "$os_type" == "Linux" ]]; then
    echo "Installing raylib for Linux..."

    # Install dependencies (for Ubuntu-based distros)
    if command -v apt &> /dev/null; then
        sudo apt update
        sudo apt install build-essential git cmake libasound2-dev libx11-dev libxcursor-dev libxrandr-dev libxi-dev libgl1-mesa-dev nlohmann-json-dev -y

    elif command -v yum &> /dev/null; then
        sudo yum groupinstall 'Development Tools' -y
        sudo yum install git cmake alsa-lib-devel libX11-devel libXcursor-devel libXrandr-devel libXi-devel mesa-libGL-devel nlohmann-json-devel -y
    else
        echo "Unsupported package manager. Please install the required dependencies manually."
        exit 1
    fi

    # Clone raylib from GitHub
    git clone https://github.com/raysan5/raylib.git ~/Downloads/raylib

    # Navigate to the raylib folder and build it
    cd ~/Downloads/raylib/src
    make

    # Optionally, install globally
    sudo make install
    cd "$current_dir"
    echo "raylib has been installed."

elif [[ "$os_type" == "Darwin" ]]; then
    echo "Installing raylib for macOS..."

    # Check if Homebrew is installed
    if ! command -v brew &> /dev/null
    then
        echo "Homebrew not found, installing Homebrew..."
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    fi

    # Install raylib using Homebrew
    brew install raylib
    brew install nlohmann-json
    echo "raylib has been installed."
else
    echo "Unsupported OS."
    exit 1
fi
