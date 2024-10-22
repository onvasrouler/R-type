@echo off
setlocal

rem Check for the first argument
if "%1" == "build" (
    rem Remove the build directory
    rd /s /q build

    rem Remove all .so files in serverModules except gameModule.so and networkModule.so
    for %%f in (serverModules\*.so) do (
        if /i not "%%~nxf" == "gameModule.so" (
            if /i not "%%~nxf" == "networkModule.so" (
                del /f "%%f"
            )
        )
    )

    rem Run CMake to configure the build
    cmake -S . -B build
    cd build
    make
    cd ..

    rem Move the compiled template module
    move /y build\modules\template\libModuleTemplate.so serverModules
    move /y serverModules\libModuleTemplate.so serverModules\ModuleTemplate.so
) else if "%1" == "clean" (
    rem Remove the build directory and all .so files in serverModules
    rd /s /q build
    del /f serverModules\*.so
) else (
    echo Usage: compile.bat [build|clean]
)

endlocal
