@echo off
setlocal

rem Check for the first argument
if "%1" == "build" (
    rem Remove the build directory
    rd /s /q build

    rem Remove all .dll files in serverModules except gameModule.dll and networkModule.dll
    for %%f in (serverModules\*.dll) do (
        if /i not "%%~nxf" == "gameModule.dll" (
            if /i not "%%~nxf" == "networkModule.dll" (
                del /f "%%f"
            )
        )
    )

    rem Run CMake to configure the build
    cmake -S . -B build
    cd build
    cmake --build .
    cd ..

    rem Move the compiled template module
    move /y build\modules\template\Debug\ModuleTemplate.dll serverModules
    move /y serverModules\ModuleTemplate.dll serverModules\ModuleTemplate.dll
) else if "%1" == "clean" (
    rem Remove the build directory and all .dll files in serverModules
    rd /s /q build
    del /f serverModules\*.dll
) else (
    echo Usage: compile.bat [build|clean]
)

endlocal
