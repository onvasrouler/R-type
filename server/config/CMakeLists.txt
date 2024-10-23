target_sources(rtype_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ConfigParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ConfigParser.hpp
)

target_sources(rtype_server_tests_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ConfigParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ConfigParser.hpp
)

target_include_directories(rtype_server_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(rtype_server_tests_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})