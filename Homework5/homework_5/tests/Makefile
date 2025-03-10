# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I../include -I/usr/include/opencv4

# Linker flags
LDFLAGS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_features2d -lstdc++fs

# Directories
SRC_DIR = ../source
TEST_DIR = ..
BUILD_DIR = .

# Source files
SRCS = $(SRC_DIR)/convert_dataset.cpp $(SRC_DIR)/serialize.cpp
TEST_SRCS = $(TEST_DIR)/test_serialize.cpp $(TEST_DIR)/test_convert_dataset.cpp $(TEST_DIR)/test_main.cpp
OBJS = $(SRCS:.cpp=.o) $(TEST_SRCS:.cpp=.o)

# Output binary
TARGET = ConvertDatasetTests_test

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

