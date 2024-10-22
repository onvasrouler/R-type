# Set the project name for the library
project(GameModule)

# Add the source files for the library
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/MultiThread.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../lib/MultiThread.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../AbstractModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../AbstractModule.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../UUID.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../UUID.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gameModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gameModule.hpp
)

# Create the shared library
add_library(gameModule SHARED ${SOURCES})

#Add include directories
target_include_directories(gameModule PRIVATE
    ${CMAKE_SOURCE_DIR}/game_engine
)

add_subdirectory(game_engine)

# Optionally, specify the include directory for the library
target_include_directories(gameModule PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_SOURCE_DIR}/..
)
