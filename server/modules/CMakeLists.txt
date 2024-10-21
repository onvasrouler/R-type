# Set the project name for modules
project(Modules)

# Include gameModule and networkModule directories
add_subdirectory(gameModule)
add_subdirectory(networkModule)

target_sources(rtype_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/AbstractModule.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/AbstractModule.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/UUID.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/UUID.hpp
)

target_include_directories(rtype_server_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
