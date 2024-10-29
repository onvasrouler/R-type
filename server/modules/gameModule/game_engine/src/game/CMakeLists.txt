target_sources(gameModule
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Game.hpp
)

target_sources(rtype_server_tests_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Game.hpp
)

target_include_directories(gameModule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(rtype_server_tests_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
