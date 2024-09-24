##
## EPITECH PROJECT, 2024
## R-type
## File description:
## Makefile
##

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++14 -Wall

# SFML flags for linking and includes
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Main Source file
SRC = 	install.cpp	\
		main.cpp
		
# File object
ELEMENTS = 	progressBar/progressBar.cpp	\
			text/textManager.cpp \
			button/button.cpp

# to fix the path without having to change every lines
TRUE_SRC 	= 	$(patsubst %,assets/elements/%, $(ELEMENTS))

# the name of the bin
TARGET = SFMLInstaller

# Build target
all: $(TARGET)

#to avoid recompile
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(TRUE_SRC) -o $(TARGET) $(SFML_FLAGS)

# Clean up
clean:
	rm -f $(TARGET)
