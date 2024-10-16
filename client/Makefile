# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall  -Wextra -Werror

# Include directories
INCLUDES = -I./

# Libraries to link with
LIBS = -lm -lpthread


LIBGUIPATH = ./src/raygui/

FULLLIBGUIPATH = $(LIBGUIPATH)raygui

LIBGUI = $(LIBGUIPATH)libraygui.so

LIBGUIFLAGS = -L$(LIBGUIPATH) -Wl,-rpath,$(LIBGUIPATH) -lraygui

# Additional include directories for Windows
ifeq ($(OS),Windows_NT)
    VCPKG_DIR = $(USERPROFILE)/vcpkg
	LIBS += -L"$(VCPKG_DIR)/installed/x64-windows/lib"
	LIBS += -L"C:\Program Files\raylib"
	LIBS += -lopengl32 -lgdi32 -lwinmm
	INCLUDES += -I"$(VCPKG_DIR)/installed/x64-windows/include"
	INCLUDES += -I"C:\Program Files\raylib"
else
	LIBS += -lGL -ldl -lrt -lX11
endif

LIBS += -lraylib 


# Files
MAIN = 	main.cpp


TRUE_ELEMENTS = $(patsubst %,src/elements/%, $(ELEMENTS))

GUIELEM = 		GButton/GButton.cpp	\
		GCheckBox/GCheckBox.cpp	\
		GColorPicker/GColorPicker.cpp	\
		GDropDown/GDropDown.cpp	\
		GGroup/GGroup.cpp	\
		GList/GList.cpp	\
		GListEx/GListEx.cpp	\
		GPannel/GPannel.cpp	\
		GProgressBar/GProgressBar.cpp	\
		GSlider/GSlider.cpp	\
		GSpinner/GSpinner.cpp	\
		GTextInput/GTextInput.cpp	\
		GTextInputBox/GTextInputBox.cpp	\
		GToggleGroup/GToggleGroup.cpp	\
		GToggleSlider/GToggleSlider.cpp	\
		GValueBox/GValueBox.cpp	\
		GWindBox/GWindBox.cpp	\
		Text/Text.cpp	\

TRUE_GUIELEM = $(patsubst %,src/elements/guiElements/guiElem/src/%, $(GUIELEM))

SRCS =	fpsCounter/fpsCounter.cpp	\
		jsonParser/jsonParser.cpp	\
		elements/guiElements/guiElem/AGuiElem.cpp	\
		elements/guiElements/gui.cpp	\
		elements/guiElements/guiFunction.cpp	\
		menu/menuManager.cpp		\
		raylibWindow/utils.cpp		\
		raylibWindow/raylibWindow.cpp
		

TRUE_SRC 	= 	$(patsubst %,src/%, $(SRCS))

OBJS = $(TRUE_SRC:.cpp=.o)
ELEMOBJS = $(TRUE_ELEMENTS:.cpp=.o)
GUIELEMOBJS = $(TRUE_GUIELEM:.cpp=.o)

# Output executable
TARGET = Rtype

# Build target
all: $(TARGET)

$(TARGET): $(LIBGUI) $(ELEMOBJS) $(GUIELEMOBJS) $(OBJS) 
	$(CXX) $(OBJS) $(GUIELEMOBJS) $(ELEMOBJS) $(MAIN) -o $(TARGET) $(LIBS) $(INCLUDES) $(LIBGUIFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LIBS) $(INCLUDES) -c $< -o $@ 

$(LIBGUI):
	mv $(FULLLIBGUIPATH).h $(FULLLIBGUIPATH).c
	$(CXX) -o $(LIBGUI) $(FULLLIBGUIPATH).c -shared -fpic -DRAYGUI_IMPLEMENTATION -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	mv $(FULLLIBGUIPATH).c $(FULLLIBGUIPATH).h

# Clean the build
clean:
	rm -f $(OBJS) $(ELEMOBJS) $(GUIELEMOBJS)

fclean: clean
	rm -f $(TARGET) $(LIBGUI)

re: fclean all