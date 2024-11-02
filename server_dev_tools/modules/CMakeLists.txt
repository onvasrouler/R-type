# Set your version of cmake
cmake_minimum_required(VERSION 3.10)

# Set the project name for modules
project(Modules)

# Set your version of C++
set(CMAKE_CXX_STANDARD 17)

# Add the subdirectory for the template module
add_subdirectory(template)
add_subdirectory(adminPanelModule)
