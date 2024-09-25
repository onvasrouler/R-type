# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++14

# Include directories
INCLUDES = -I./

# Libraries to link with
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Files
MAIN = 	main.cpp

ELEMENTS = raylibText/raylibText.cpp	\
		   raylibButton/raylibButton.cpp	\

TRUE_ELEMENTS = $(patsubst %,src/elements/%, $(ELEMENTS))

SRCS =	fpsCounter/fpsCounter.cpp	\
		jsonParser/jsonParser.cpp	\
		menu/menu.cpp		\
		menu/menuManager.cpp		\
		raylibWindow/utils.cpp		\
		raylibWindow/raylibWindow.cpp \

TRUE_SRC 	= 	$(patsubst %,src/%, $(SRCS))

OBJS = $(TRUE_SRC:.cpp=.o)
ELEMOBJS = $(TRUE_ELEMENTS:.cpp=.o)

# Output executable
TARGET = raylib_example

# Build target
all: $(TARGET)

$(TARGET): $(ELEMOBJS) $(OBJS)
	$(CXX) $(OBJS) $(ELEMOBJS) $(MAIN) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean the build
clean:
	rm -f $(OBJS) $(ELEMOBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all