# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++14

# Include directories
INCLUDES = -I.

# Libraries to link with
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Files
MAIN = 	main.cpp

SRCS = 	raylibWindow/raylibWindow.cpp \
		raylibText/raylibText.cpp	\
		fpsCounter/fpsCounter.cpp	\
		jsonParser/jsonParser.cpp	\

TRUE_SRC 	= 	$(patsubst %,src/%, $(SRCS))

OBJS = $(TRUE_SRC:.cpp=.o)

# Output executable
TARGET = raylib_example

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(MAIN) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean the build
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all