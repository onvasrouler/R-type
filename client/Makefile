# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++14

# Include directories
INCLUDES = -I.
# Libraries to link with
LIBS = -lm -lpthread 

# Additional include directories for Windows
ifeq ($(OS),Windows_NT)
    VCPKG_DIR = $(USERPROFILE)/vcpkg
	LIBS += -L"$(VCPKG_DIR)/installed/x64-windows/lib"
	LIBS += -L"C:\Program Files\raylib"
	LIBS += -lopengl32 -lgdi32 -lwinmm
	INCLUDES += -I"$(VCPKG_DIR)/installed/x64-windows/include"
	INCLUDES += -I"C:\Program Files\raylib"
else
	LIBS += -lGL -ldl -lrt -lX11 -lvcpkg -ljsoncpp 
endif

LIBS += -lraylib 


# Files
MAIN = 	main.cpp

SRCS = 	raylibWindow/raylibWindow.cpp \
		raylibText/raylibText.cpp	\
		fpsCounter/fpsCounter.cpp	\
		jsonParser/jsonParser.cpp	\
		menu/menuManager.cpp		\

TRUE_SRC 	= 	$(patsubst %,src/%, $(SRCS))

OBJS = $(TRUE_SRC:.cpp=.o)

# Output executable
TARGET = Rtype

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(MAIN) -o $(TARGET) $(LIBS) $(INCLUDES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LIBS) $(INCLUDES) -c $< -o $@ 

# Clean the build
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all