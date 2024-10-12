@echo off

REM Define variables
set VCPKG_REPO=https://github.com/microsoft/vcpkg.git
set VCPKG_DIR=%USERPROFILE%\vcpkg
set REPO_URL=git@github.com:onvasrouler/R-type.git
set REPO_DIR=r-types
set BRANCH=dev
set VCPKG_ROOT=%VCPKG_DIR%

REM Function to check if a command exists
echo "Checking for Git installation..."
where git >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo "Error: Git is not installed. Please install Git."
    pause
    exit /b 1
)

echo "Checking for CMake installation..."
where cmake >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo "Error: CMake is not installed. Please install CMake."
    pause
    exit /b 1
)

echo "Checking for curl installation..."
where curl >nul 2>&1
if %ERRORLEVEL% neq 0 (
    echo "Error: curl is not installed. Please install curl."
    pause
    exit /b 1
)

REM Clone and set up vcpkg
if not exist "%VCPKG_DIR%" (
    echo "Cloning vcpkg..."
    git clone %VCPKG_REPO% %VCPKG_DIR%
    cd %VCPKG_DIR%
    bootstrap-vcpkg.bat
    echo "vcpkg cloned and bootstrapped."
) else (
    echo "vcpkg already installed at %VCPKG_DIR%"
)

REM Install required packages with vcpkg (boost and gtest)
echo "Installing required packages (boost and gtest)..."
%VCPKG_DIR%\vcpkg install boost gtest
if %ERRORLEVEL% neq 0 (
    echo "Error installing packages with vcpkg."
    pause
    exit /b 1
)
echo "Required packages installed."

REM Clone the project repository
if not exist "%REPO_DIR%" (
    echo "Cloning project repository..."
    git clone %REPO_URL% %REPO_DIR%
    cd %REPO_DIR%
    git checkout %BRANCH%
    if %ERRORLEVEL% neq 0 (
        echo "Error: Could not checkout branch %BRANCH%."
        pause
        exit /b 1
    )
    echo "Project repository cloned and branch %BRANCH% checked out."
) else (
    echo "Project repository already exists at %REPO_DIR%"
    cd %REPO_DIR%
)

REM Remove the existing build directory if it exists
if exist build (
    rmdir /s /q build
)
mkdir build
cd build

REM Create and configure CMake build
echo "Creating and configuring CMake build..."
cmake -DCMAKE_TOOLCHAIN_FILE=%VCPKG_DIR%\scripts\buildsystems\vcpkg.cmake ..
if %ERRORLEVEL% neq 0 (
    echo "Error during CMake configuration."
    pause
    exit /b 1
)
echo "CMake configuration successful."

echo "Building the project..."
cmake --build .
if %ERRORLEVEL% neq 0 (
    echo "Error during build."
    pause
    exit /b 1
)
echo "Project build completed."

REM Start the server
echo "Starting the server..."
cd server\Debug
cd
dir
.\r-type_server
if %ERRORLEVEL% neq 0 (
    echo "Error starting the server."
    pause
    exit /b 1
)
cd ..\..\..
echo "Server started successfully."

pause
exit /b 0
