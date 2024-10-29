@echo off
setlocal

set server_binary="r-type_server.exe"
set head_server_binary="r-type_head_server.exe"
set client_binary="r-type_client.exe"
set tests_binary="r-type_tests.exe"
set serverModulesDir="serverModules"

rem Remove existing build artifacts
rd -r -Force build

rem Control flow based on input argument
echo %1
if "%1" == "clean" (
    call :clean_all
    goto :eof
) else if "%1" == "tests" (
    call :compile_tests
    goto :eof
) else if "%1" == "server" (
    call :compile_server
    goto :eof
) else if "%1" == "client" (
    call :compile_client
    goto :eof
) else if "%1" == "HeadServer" (
    call :compile_head_server
    goto :eof
) else (
    call :compile
    goto :eof
)

:clean_server
    del /f %server_binary%
    del /f %serverModulesDir%\*
    del /f server_dev_tools\server\config\windows\*.lib
    del /f server_dev_tools\%serverModulesDir%\gameModule.dll
    del /f server_dev_tools\%serverModulesDir%\networkModule.dll
    del /f server_dev_tools\%serverModulesDir%\logModule.dll
    del /f server_dev_tools\%server_binary%
    del /f server_dev_tools\source_code\*.cpp
    del /f server_dev_tools\source_code\*.hpp
goto :eof

:clean_head_server
    del /f %head_server_binary%
goto :eof

:clean_client
    del /f %client_binary%
goto :eof

:clean_tests
    del /f %tests_binary%
goto :eof

:clean_all
    call :clean_server
    call :clean_head_server
    call :clean_client
    call :clean_tests
goto :eof

:copy_server_source_code
    copy server\modules\MultiThread.* server_dev_tools\source_code
    copy server\modules\AbstractModule.* server_dev_tools\source_code
    copy server\modules\UUID.* server_dev_tools\source_code
goto :eof

:move_server_and_modules
    move /y build\server\Debug\%server_binary% .
    move /y build\server\modules\gameModule\Debug\*.dll .
    move /y build\server\modules\networkModule\Debug\*.dll .
    move /y build\server\modules\logModule\Debug\*.dll .
    move /y libgameModule.dll gameModule.dll
    move /y libnetworkModule.dll networkModule.dll
    move /y liblogModule.dll logModule.dll
    move /y *.dll %serverModulesDir%
goto :eof

:setup_dev_tools
    move /y build\server_dev_tools\source_code\Debug\moduleSourceCode.lib server_dev_tools\server\config\windows
    copy %serverModulesDir%\*.dll server_dev_tools\%serverModulesDir%
    copy %server_binary% server_dev_tools
goto :eof

:compile_server
    call :clean_server
    call :copy_server_source_code
    echo "Compiling server"
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DHEAD_SERVER=OFF -DCLIENT=OFF -DCMAKE_TOOLCHAIN_FILE="C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    call :move_server_and_modules
    call :setup_dev_tools
goto :eof

:compile_head_server
    call :clean_head_server
    echo "Compiling Head Server"
    cmake -S . -B build -DTESTS=OFF -DSERVER=OFF -DHEAD_SERVER=ON -DCLIENT=OFF -DCMAKE_TOOLCHAIN_FILE="C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    move /y build\HeadServer\Debug\%head_server_binary% .
goto :eof

:compile_client
    call :clean_client
    echo "Compiling Client"
    cmake -S . -B build -DTESTS=OFF -DSERVER=OFF -DHEAD_SERVER=OFF -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE="C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    move /y build\client\%client_binary% .
goto :eof

:compile_tests
    call :clean_all
    echo "Compiling Tests"
    cmake -S . -B build -DTESTS=ON -DSERVER=ON -DHEAD_SERVER=ON -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE="C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    .\build\tests\Debug\%tests_binary%
goto :eof

:compile
    call :clean_client
    call :clean_server
    call :clean_head_server
    echo "Compiling All"
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DHEAD_SERVER=ON -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE="C:/Users/tenne/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build .
    cd ..
    call :move_server_and_modules
    move /y build\client\%client_binary% .
goto :eof
