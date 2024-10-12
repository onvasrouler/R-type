@echo off

REM Define variables
set VCPKG_REPO=https://github.com/microsoft/vcpkg.git
set VCPKG_DIR=%USERPROFILE%\vcpkg
set REPO_URL=git@github.com:onvasrouler/R-type.git
set REPO_DIR=r-types
set BRANCH=dev

REM Function to check if a command exists (for batch, this is simplified)
where git >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo "Error: Git is not installed. Please install Git."
    exit /b 1
)

where cmake >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo "Error: CMake is not installed. Please install CMake."
    exit /b 1
)

where curl >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo "Error: curl is not installed. Please install curl."
    exit /b 1
)

REM Clone and set up vcpkg
if not exist "%VCPKG_DIR%" (
    echo "Cloning vcpkg..."
    git clone %VCPKG_REPO% %VCPKG_DIR%
    cd %VCPKG_DIR%
    bootstrap-vcpkg.bat
) else (
    echo "vcpkg already installed at %VCPKG_DIR%"
)

REM Install required packages with vcpkg
echo "Installing required packages..."
%VCPKG_DIR%\vcpkg install boost gtest uuid

REM Clone the project repository
if not exist "%REPO_DIR%" (
    echo "Cloning project repository..."
    git clone %REPO_URL% %REPO_DIR%
    cd %REPO_DIR%
    git checkout %BRANCH%
) else (
    echo "Project repository already exists at %REPO_DIR%"
    cd %REPO_DIR%
)

REM Create and configure CMake build
echo "Configuring build with CMake..."
mkdir build && cd build && cmake .. && cmake --build .

REM Start the server
echo "Starting the server..."
cd build && cd server && ./r-type_server
