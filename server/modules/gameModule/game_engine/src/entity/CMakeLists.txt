target_sources(gameModule
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ACharacter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ACharacter.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/AEntity.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/AEntity.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/IEntity.hpp
)

add_subdirectory(bullet)
add_subdirectory(character)

target_include_directories(gameModule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
