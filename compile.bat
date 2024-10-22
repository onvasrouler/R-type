@echo off
setlocal

rem Remove existing build artifacts
rd /s /q build
rd /s /q serverModules
del /f r-type_server.exe
del /f r-type_client.exe
del /f r-type_tests.exe

if "%1" == "clean" (
    rd /s /q build
    rd /s /q serverModules
    del /f r-type_server.exe
    del /f r-type_client.exe
    del /f r-type_tests.exe
    rd /s /q server_dev_tools\serverModules
    del /f server_dev_tools\r-type_server.exe
    del /f server_dev_tools\server\config\windows\*.lib
) else if "%1" == "tests" (
    cmake -S . -B build -DTESTS=ON -DCMAKE_TOOLCHAIN_FILE="C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    .\build\tests\r-type_tests.exe
) else if "%1" == "server" (
    del /f serverModules\*
    del /f server_dev_tools\server\config\windows\*.lib
    rd /s /q server_dev_tools\serverModules\gameModule.dll
    rd /s /q server_dev_tools\serverModules\networkModule.dll
    del /f server_dev_tools\r-type_server.exe
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DCLIENT=OFF -DCMAKE_TOOLCHAIN_FILE="C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    move /y build\server\Debug\r-type_server.exe .
    move /y build\server\modules\gameModule\Debug\*.dll .
    move /y build\server\modules\networkModule\Debug\*.dll .
    move /y libgameModule.dll gameModule.dll
    move /y libnetworkModule.dll networkModule.dll
    move /y build\server_dev_tools\source_code\Debug\moduleSourceCode.lib server_dev_tools\server\config\windows
    move /y server_dev_tools\server\config\windows\moduleSourceCode.lib server_dev_tools\server\config\windows\moduleSourceCode.lib
    mkdir serverModules
    move /y gameModule.dll serverModules
    move /y networkModule.dll serverModules
    mkdir server_dev_tools\serverModules
    copy /y serverModules\*.dll server_dev_tools\serverModules
    copy /y r-type_server.exe server_dev_tools
    attrib +r server_dev_tools\serverModules\*.dll
) else if "%1" == "client" (
    cmake -S . -B build -DTESTS=OFF -DSERVER=OFF -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE="C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    move /y build\client\r-type_client.exe .
) else (
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE="C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    move /y build\server\r-type_server.exe .
    move /y build\client\r-type_client.exe .
)

endlocal
