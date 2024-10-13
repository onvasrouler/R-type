@echo off
echo Installing nlohmann/json for Windows...

REM Check if vcpkg is installed
where vcpkg >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo vcpkg is not installed. Please install vcpkg from https://github.com/microsoft/vcpkg and try again.
    pause
    exit /b 1
)

REM Install nlohmann/json using vcpkg
vcpkg install nlohmann-json

echo Installation complete.
pause
