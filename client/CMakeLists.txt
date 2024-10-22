cmake_minimum_required(VERSION 3.10)

project(RType VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/elements)

if(WIN32)
    set(VCPKG_DIR "$ENV{USERPROFILE}/vcpkg")
    include_directories(${VCPKG_DIR}/installed/x64-windows/include)
    link_directories(${VCPKG_DIR}/installed/x64-windows/lib)
    set(LIBS opengl32 gdi32 winmm raylib)  # Use opengl32 for Windows
else()
    set(LIBS GL dl rt X11 raylib pthread)  # Use GL for Unix-based systems
endif()

set(SRC_FILES
    src/fpsCounter/fpsCounter.cpp
    src/jsonParser/jsonParser.cpp
    src/elements/guiElements/guiElem/AGuiElem.cpp
    src/elements/guiElements/gui.cpp
    src/elements/guiElements/guiFunction.cpp
    src/menu/menuManager.cpp
    src/raylibWindow/utils.cpp
    src/raylibWindow/raylibWindow.cpp
)

set(GUIELEM_FILES
    src/elements/guiElements/guiElem/src/GButton/GButton.cpp
    src/elements/guiElements/guiElem/src/GCheckBox/GCheckBox.cpp
    src/elements/guiElements/guiElem/src/GColorPicker/GColorPicker.cpp
    src/elements/guiElements/guiElem/src/GDropDown/GDropDown.cpp
    src/elements/guiElements/guiElem/src/GGroup/GGroup.cpp
    src/elements/guiElements/guiElem/src/GList/GList.cpp
    src/elements/guiElements/guiElem/src/GListEx/GListEx.cpp
    src/elements/guiElements/guiElem/src/GPannel/GPannel.cpp
    src/elements/guiElements/guiElem/src/GProgressBar/GProgressBar.cpp
    src/elements/guiElements/guiElem/src/GSlider/GSlider.cpp
    src/elements/guiElements/guiElem/src/GSpinner/GSpinner.cpp
    src/elements/guiElements/guiElem/src/GTextInput/GTextInput.cpp
    src/elements/guiElements/guiElem/src/GTextInputBox/GTextInputBox.cpp
    src/elements/guiElements/guiElem/src/GToggleGroup/GToggleGroup.cpp
    src/elements/guiElements/guiElem/src/GToggleSlider/GToggleSlider.cpp
    src/elements/guiElements/guiElem/src/GValueBox/GValueBox.cpp
    src/elements/guiElements/guiElem/src/GWindBox/GWindBox.cpp
    src/elements/guiElements/guiElem/src/Text/Text.cpp
)

set(MAIN_FILE main.cpp)

set(TARGET_NAME Rtype)

add_executable(${TARGET_NAME} ${SRC_FILES} ${GUIELEM_FILES} ${MAIN_FILE})

set(LIBGUIPATH ${CMAKE_SOURCE_DIR}/client/src/raygui)

add_custom_target(raygui_dll ALL DEPENDS ${LIBGUIPATH}/raygui.dll ${LIBGUIPATH}/librayguidll.a)


add_library(raygui SHARED ${LIBGUIPATH}/raygui.c )
target_compile_definitions(raygui PRIVATE RAYGUI_IMPLEMENTATION)
target_include_directories(raygui PUBLIC ${LIBGUIPATH})

target_link_libraries(${TARGET_NAME} raygui ${LIBS})  # Link the correct libraries

if(APPLE)
    target_link_libraries(${TARGET_NAME} "-framework OpenGL" "-framework Cocoa")
    target_link_libraries(raygui "-framework OpenGL" "-framework Cocoa")
else()
    # The previous section is enough. Remove GL here for Windows.
endif()

target_link_libraries(${TARGET_NAME} raygui)

add_custom_command(
    TARGET raygui POST_BUILD
    COMMAND mv ${LIBGUIPATH}/raygui.c ${LIBGUIPATH}/raygui.h
)
