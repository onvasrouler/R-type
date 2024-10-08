target_sources(rtype_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ACharacter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ACharacter.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/AEntity.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/AEntity.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/IEntity.hpp
)

add_subdirectory(src)
add_subdirectory(special)
