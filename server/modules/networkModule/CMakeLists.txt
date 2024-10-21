# Set the project name for the library
project(NetworkModule)

# Add the source files for the library
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../AbstractModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../AbstractModule.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../UUID.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../UUID.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Client.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Client.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/networkModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/networkModule.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UDPServer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UDPServer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UDPError.hpp
)

# Create the shared library
add_library(networkModule SHARED ${SOURCES})

# Optionally, specify the include directory for the library
target_include_directories(networkModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
