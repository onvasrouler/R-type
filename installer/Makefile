# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++14 -Wall

# SFML flags for linking and includes
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source file and target
SRC = 	install.cpp	\
		main.cpp
		
ELEMENTS = 	progressBar/progressBar.cpp	\
			utils/utils.cpp	\
			text/textManager.cpp \
			button/button.cpp

TRUE_SRC 	= 	$(patsubst %,assets/elements/%, $(ELEMENTS))


TARGET = SFMLInstaller

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(TRUE_SRC) -o $(TARGET) $(SFML_FLAGS)

# Clean up
clean:
	rm -f $(TARGET)
