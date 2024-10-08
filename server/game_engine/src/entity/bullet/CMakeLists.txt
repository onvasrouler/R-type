target_sources(rtype_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Bullet.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Bullet.hpp
)

target_include_directories(rtype_server_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
