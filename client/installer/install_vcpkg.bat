@echo off
SETLOCAL

REM Define vcpkg URL and installation directory
SET VCPKG_DIR=%USERPROFILE%\vcpkg
SET VCPKG_GITHUB_URL=https://github.com/microsoft/vcpkg.git

REM Clone vcpkg from GitHub
if exist "%VCPKG_DIR%" (
    echo vcpkg directory already exists, skipping clone.
) else (
    echo Cloning vcpkg...
    git clone %VCPKG_GITHUB_URL% "%VCPKG_DIR%"
)

REM Navigate to the vcpkg directory
cd "%VCPKG_DIR%"

REM Bootstrap vcpkg
echo Bootstrapping vcpkg...
call bootstrap-vcpkg.bat

REM Add vcpkg to the system PATH
setx PATH "%PATH%;%VCPKG_DIR%"

echo vcpkg installation complete!

REM clean up
cd ..
rmdir /s /q vcpkg

ENDLOCAL
pause
