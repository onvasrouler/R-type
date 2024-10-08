target_sources(rtype_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ATools.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ATools.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ITools.hpp
)

add_subdirectory(src)
add_subdirectory(special)
