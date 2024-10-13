@echo off

set VCPKG_REPO=https://github.com/microsoft/vcpkg.git
set VCPKG_DIR=%USERPROFILE%\vcpkg
set REPO_URL=git@github.com:onvasrouler/R-type.git
set REPO_DIR=r-types
set BRANCH=dev
set VCPKG_ROOT=%VCPKG_DIR%

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

if not exist "%VCPKG_DIR%" (
    echo "Cloning vcpkg..."
    git clone %VCPKG_REPO% %VCPKG_DIR%
    cd %VCPKG_DIR%
    bootstrap-vcpkg.bat
    echo "vcpkg cloned and bootstrapped."
) else (
    echo "vcpkg already installed at %VCPKG_DIR%"
)

echo "Installing required packages (boost and gtest)..."
%VCPKG_DIR%\vcpkg install boost gtest
if %ERRORLEVEL% neq 0 (
    echo "Error installing packages with vcpkg."
    pause
    exit /b 1
)
echo "Required packages installed."

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

if exist build (
    rmdir /s /q build
)
mkdir build
cd build

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

echo "Starting the client..."
cd client2\Debug
.\r-type_client.exe
if %ERRORLEVEL% neq 0 (
    echo "Error starting the client."
    pause
    exit /b 1
)
cd ..\..\..
echo "Client started successfully."

pause
exit /b 0
