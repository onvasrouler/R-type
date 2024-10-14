# Makefile for SFML_Menu project

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -pthread

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
ASSETS_DIR = chipset
DEBUG_OUTPUT_DIR = $(BIN_DIR)

SRCS = main.cpp $(SRC_DIR)/Menu.cpp $(SRC_DIR)/Game.cpp $(SRC_DIR)/GameObject.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/r-type_client

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)
	@echo "Copying assets to Debug directory"
	@mkdir -p $(DEBUG_OUTPUT_DIR)/chipset
	@cp -r $(ASSETS_DIR)/* $(DEBUG_OUTPUT_DIR)/chipset

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean