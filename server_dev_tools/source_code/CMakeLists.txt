# Set the project name for the library
project(ModuleSourceCode)

# Find Boost
find_package(Boost REQUIRED COMPONENTS system filesystem)

# Add the source files for the library
set(SOURCES
    AbstractModule.cpp
    AbstractModule.hpp
    MultiThread.cpp
    MultiThread.hpp
    UUID.cpp
    UUID.hpp
)

# Create the shared library
add_library(moduleSourceCode STATIC ${SOURCES})
if(Boost_FOUND)
    message(STATUS "Boost found: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(networkModule PRIVATE Boost::system Boost::filesystem)
else()
    message(FATAL_ERROR "Boost not found")
endif()

# Optionally, specify the include directory for the library
target_include_directories(moduleSourceCode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})