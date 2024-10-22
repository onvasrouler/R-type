#Set your version of cmake
cmake_minimum_required(VERSION 3.10)
#Set the project name for modules
project(Modules)
#Set your version of C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

#Add the include directories for your module
set(MODULE_INCLUDE ${CMAKE_SOURCE_DIR}/server/config)
if(WIN32)
else()
    set(SOURCE_CODE ${CMAKE_SOURCE_DIR}/server/config/unix/moduleSourceCode.a)
endif()
add_subdirectory(modules)
