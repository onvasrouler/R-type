cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SFMLInstaller VERSION 1.0)

# Set the C++ standard to C++11 or later
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the executable
add_executable(SFMLInstaller installer.cpp)

# Link SFML libraries to the executable
target_link_libraries(SFMLInstaller sfml-graphics sfml-window sfml-system)

# Set paths to where SFML includes and libraries might be (optional)
# In case you have non-standard SFML installation paths, specify them below:
# include_directories(/path/to/sfml/include)
# link_directories(/path/to/sfml/lib)
