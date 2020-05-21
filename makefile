CXX = g++
CXXFLAGS = -g -Wall -Wextra
LDLIBS = -lGL -lGLEW

SOURCE_DIR := ./src/
BUILD_DIR  := ./build/
TARGET_DIR := ./

NAME := snake
HEADERS := $(wildcard $(SOURCE_DIR)*.hpp)
SOURCES := $(wildcard $(SOURCE_DIR)*.cpp)
OBJECTS := $(SOURCES:$(SOURCE_DIR)%.cpp=$(BUILD_DIR)%.o)

TARGET := $(TARGET_DIR)$(NAME)

#GL_INCLUDE = 


.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDLIBS) $^ -o $@

$(BUILD_DIR)%.o: $(SOURCE_DIR)%.cpp $(HEADERS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -c -o $@



.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)