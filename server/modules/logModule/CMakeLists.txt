# Set the project name for the library
project(LogModule)

# Add the source files for the library
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../MultiThread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../MultiThread.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../AbstractModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../AbstractModule.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../UUID.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../UUID.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logModule.hpp
)

# Create the shared library
add_library(logModule SHARED ${SOURCES})

# Optionally, specify the include directory for the library
target_include_directories(logModule PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_include_directories(rtype_server_tests_lib PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_SOURCE_DIR}/..
)
