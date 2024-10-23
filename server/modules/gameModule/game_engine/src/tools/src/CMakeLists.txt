target_sources(gameModule
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Damage.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Hp.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Level.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Type.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Velocity.hpp
)

target_sources(rtype_server_tests_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Damage.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Hp.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Level.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Type.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Velocity.hpp
)

target_include_directories(gameModule PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(rtype_server_tests_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
