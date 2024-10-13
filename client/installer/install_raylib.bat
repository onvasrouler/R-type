@echo off
echo Installing raylib for Windows...

REM define the path of the current folder
set CURRENT_FOLDER=%~dp0

REM check if the script is running as admin
net session >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo This script requires admin privileges. Please run it as an administrator.
    pause
    exit /b 1
)

REM Check if Git is installed
where git >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo Git is not installed. Please install Git and try again.
    pause
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
    pause
    exit /b 1
)

REM Copy the raylib library to the C:Program Files folder
cd ..
mkdir "C:\Program Files\raylib" 2> nul
Copy /y src\raylib.h "C:\Program Files\raylib"
Copy /y src\libraylib.a "C:\Program Files\raylib"

echo raylib has been installed.

REM Clean up
cd ..
rmdir /s /q raylib
