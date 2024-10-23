target_sources(gameModule
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Enemy.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Enemy.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Player.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Player.hpp
)

target_sources(rtype_server_tests_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Enemy.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Enemy.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Player.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Player.hpp
)

target_include_directories(gameModule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(rtype_server_tests_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
