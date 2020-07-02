CXX = g++
CXXFLAGS = -g -Wall -Wextra
LDLIBS := $(shell pkg-config --libs glew glfw3)

SOURCE_DIR := ./src/
BUILD_DIR  := ./build/
TARGET_DIR := ./

NAME := snake

HEADERS := $(wildcard $(SOURCE_DIR)*.hpp)
SOURCES := $(wildcard $(SOURCE_DIR)*.cpp)
OBJECTS := $(SOURCES:$(SOURCE_DIR)%.cpp=$(BUILD_DIR)%.o)

TARGET := $(TARGET_DIR)$(NAME)

#GL_INCLUDE = `pkg-config --cflags glew`


.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $^ $(LDLIBS) -o $@

$(BUILD_DIR)%.o: $(SOURCE_DIR)%.cpp $(HEADERS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $< $(CXXFLAGS) -c -o $@


.PHONY: run
run: $(TARGET)
	$(TARGET)


.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)
