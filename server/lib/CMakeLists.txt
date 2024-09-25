target_sources(rtype_server_lib
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Buffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MultiThread.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Mutex.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ScopedLock.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Thread.cpp
)