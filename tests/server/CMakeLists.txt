target_sources(r-type_tests
  PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/testAbstractModule.cpp
        ${CMAKE_CURRENT_LIST_DIR}/testBuffer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/testMultiThread.cpp
        ${CMAKE_CURRENT_LIST_DIR}/testMutex.cpp
        ${CMAKE_CURRENT_LIST_DIR}/testScopedLock.cpp
)
