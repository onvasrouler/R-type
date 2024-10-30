@echo off
setlocal

set TOOLCHAIN_FILE_PATH=%USERPROFILE%\vcpkg\scripts\buildsystems\vcpkg.cmake
set server_binary="r-type_server.exe"
set head_server_binary="r-type_head_server.exe"
set client_binary="r-type_client.exe"
set tests_binary="r-type_tests.exe"
set serverModulesDir="serverModules"

echo "dcmake_toolchain_file: %TOOLCHAIN_FILE_PATH%"

rem Clean up previous builds
if exist build (
    rmdir /s /q build
)
if exist Result (
    rmdir /s /q Result
)
if exist r-type_server (
    del r-type_server
)
if exist r-type_client (
    del r-type_client
)
if exist r-type_tests (
    del r-type_tests
)

rem Detect operating system
set "OS=%OS%"
if "%OS%"=="Windows_NT" (
    echo Running on Windows
) else (
    echo Running on Linux
)
cmake --build . --target clean
if "%~1"=="clean" (
    exit /b
) else if "%~1"=="tests" (
    echo Building tests
    cmake -S . -B build -DTESTS=ON -DSERVER=ON -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE_PATH% -Wno-dev -D_WIN32_WINNT=0x0601
    cmake --build build --config Release
    start "" "build/R-type.sln"
    cd build
    if "%OS%"=="Windows_NT" (
        echo Running tests on Windows
        build\tests\r-type_tests.exe
    ) else (
        echo Running tests on Linux
        build/tests/r-type_tests
    )
) else if "%~1"=="server" (
    echo Building server
    rmdir /s /q serverModules
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DCLIENT=OFF -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE_PATH% -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    move /Y build\server\Debug\r-type_server.exe .
    mkdir serverModules
    move /Y build\server\modules\gameModule\Debug\gameModule.dll serverModules
    move /Y build\server\modules\networkModule\Debug\networkModule.dll serverModules
    move /Y build\server\modules\logModule\Debug\logModule.dll serverModules
) else if "%~1"=="client" (
    echo Building client
    cmake -S . -B build -DTESTS=OFF -DSERVER=OFF -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE_PATH% -DCMAKE_PREFIX_PATH=C:/Users/aimer/vcpkg/installed/x64-windows -Wno-dev -D_WIN32_WINNT=0x0601
    IF ERRORLEVEL 1 (
        echo CMake configuration failed!
        exit /b 1
    )
    cd build
    cmake --build .
    IF ERRORLEVEL 1 (
        echo Build failed! See build_log.txt for details.
        exit /b 1
    )
    cd ..
    mkdir Result\client
    xcopy build\client\Debug\* Result\client\ /E /I /Y
    copy build\bin\Debug\raygui.dll Result\client\
    xcopy client\config Result\client\config\ /E /I /Y
    xcopy client\assets Result\client\assets\ /E /I /Y

    echo "Client built !"
) else (
    echo Building server and client
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE_PATH% -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    move /Y build/server/r-type_server .
    move /Y build/client/r-type_client .
)

.\build\tests\Debug\%tests_binary%
goto :eof

endlocal