
@echo off

SET VCPKG_DIR=%USERPROFILE%\vcpkg


REM define VCPKG_ROOT environment variable
setx VCPKG_ROOT %VCPKG_DIR%

REM add raylib to the system path
setx PATH "%PATH%;%VCPKG_DIR%"
pause
