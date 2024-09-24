@echo off
echo Installing raylib for Windows...

current_dir=%cd%

REM Check if Git is installed
where git >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo Git is not installed. Please install Git and try again.
    exit /b 1
)

REM Check if CMake is installed
where cmake >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo CMake is not installed. Please install CMake and try again.
    exit /b 1
)

REM Clone raylib from GitHub
git clone https://github.com/raysan5/raylib.git

REM Navigate to the raylib folder and build it using MinGW or MSVC
cd raylib/src
mingw32-make 2> nul || nmake
if %ERRORLEVEL% neq 0 (
    echo Failed to build raylib. Please ensure you have a valid compiler installed.
    exit /b 1
)

cd ../..
echo raylib has been installed.
pause
