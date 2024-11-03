@echo off
setlocal

rem Définition des variables
set TOOLCHAIN_FILE_PATH=%USERPROFILE%\vcpkg\scripts\buildsystems\vcpkg.cmake
set server_binary=r-type_server.exe
set client_binary=r-type_client.exe
set tests_binary=r-type_tests.exe
set serverModulesDir=serverModules

echo cmake_toolchain_file: %TOOLCHAIN_FILE_PATH%

rem Nettoyage des builds précédents
if exist build (
    rmdir /s /q build
)
if exist Result (
    rmdir /s /q Result
)
if exist %server_binary% (
    del %server_binary%
)
if exist %client_binary% (
    del %client_binary%
)
if exist %tests_binary% (
    del %tests_binary%
)

rem Détection du système d'exploitation
set "OS=%OS%"
if "%OS%"=="Windows_NT" (
    echo Exécution sous Windows
) else (
    echo Exécution sous Linux
)
cmake --build . --target clean

if "%~1"=="clean" (
    exit /b
) else if "%~1"=="tests" (
    echo Compilation des tests
    cmake -S . -B build -DTESTS=ON -DSERVER=ON -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE_PATH% -Wno-dev -D_WIN32_WINNT=0x0601
    cmake --build build --config Release
    start "" "build/R-type.sln"
    cd build
    if "%OS%"=="Windows_NT" (
        echo Exécution des tests sous Windows
        build\tests\Debug\r-type_tests.exe
    ) else (
        echo Exécution des tests sous Linux
        build/tests/Debug/r-type_tests
    )
) else if "%~1"=="server" (
    call :compile_server
    call :move_server_to_result
) else if "%~1"=="client" (
    call :compile_client
    call :move_client_to_result
) else (
    echo Aucun argument fourni. Compilation du serveur et du client...
    call :compile_server
    call :compile_client
    call :move_server_to_result
    call :move_client_to_result
)

goto :eof

:clean_server
    if exist %server_binary% del /f %server_binary%
    if exist %serverModulesDir%\* del /f %serverModulesDir%\*
    if exist server_dev_tools\server\config\windows\*.lib del /f server_dev_tools\server\config\windows\*.lib
goto :eof

:clean_client
    if exist %client_binary% del /f %client_binary%
goto :eof

:clean_tests
    if exist %tests_binary% del /f %tests_binary%
goto :eof

:clean_all
    call :clean_server
    call :clean_client
    call :clean_tests
goto :eof

:compile_server
    echo Compilation du serveur...
    call :clean_server
    cmake -S . -B build -DTESTS=OFF -DSERVER=ON -DCLIENT=OFF -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE_PATH% -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build . --target r-type_server --config Debug
    cd ..
goto :eof

:compile_client
    echo Compilation du client...
    call :clean_client
    cmake -S . -B build -DTESTS=OFF -DSERVER=OFF -DCLIENT=ON -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE_PATH% -Wno-dev -D_WIN32_WINNT=0x0601
    cd build
    cmake --build . --target r-type_client --config Debug
    cd ..
goto :eof

:move_server_to_result
    echo Déplacement des fichiers du serveur vers Result\server...

    rem
    if not exist Result\server (
        mkdir Result\server
    )

    rem
    if exist build\server\Debug\%server_binary% (
        move /y build\server\Debug\%server_binary% Result\server\
    )

    echo Les fichiers du serveur ont été déplacés vers Result\server.
goto :eof

:move_client_to_result
    echo Déplacement des fichiers du client vers Result\client...

    rem
    if not exist Result\client (
        mkdir Result\client
    )

    rem
    if exist build\client\Debug\* (
        xcopy build\client\Debug\* Result\client\ /E /I /Y
    )

    rem
    if exist build\bin\Debug\raygui.dll (
        copy build\bin\Debug\raygui.dll Result\client\
    )

    if exist client\config (
        xcopy client\config Result\client\config\ /E /I /Y
    )
    if exist client\assets (
        xcopy client\assets Result\client\assets\ /E /I /Y
    )

    echo Les fichiers du client ont été déplacés vers Result\client.
goto :eof

endlocal
